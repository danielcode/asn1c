#ifndef	ASN1FIX_CRANGE_H
#define	ASN1FIX_CRANGE_H

typedef struct asn1cnst_edge_s {
	enum asn1cnst_range_edge {
		ARE_MIN,
		ARE_MAX,
		ARE_VALUE,
	} type;
	int lineno;	/* Line where the corresponding token was found */
	asn1_integer_t value;	/* Value when type is ARE_VALUE */
} asn1cnst_edge_t;

typedef struct asn1cnst_range_s {
	asn1cnst_edge_t left;	/* MIN from (MIN..10) */
	asn1cnst_edge_t right;	/* 10 from (MIN..10) */

	/* If range is split in parts, these are the parts */
	struct asn1cnst_range_s **elements;
	int el_count;
	int el_size;

	int empty_constraint;	/* If yes, too bad. */
	int extensible;		/* Extension marker (...) present. */

	int not_PER_visible;	/* Contains non PER-visible components */
} asn1cnst_range_t;

/*
 * Compute the PER-visible constraint range.
 * 
 * (expr_type) must have the type of the top-level parent ASN.1 type.
 * (required_type) must be one of ACT_EL_RANGE, ACT_CT_SIZE or ACT_CT_FROM.
 * (minmax) and (expectation_met) should be 0.
 * ERRORS:
 * 	EINVAL:	Mandatory arguments missing.
 * 	ENOMEM:	Memory allocation failure.
 * 	EPERM:	Invalid constraint reference.
 */
asn1cnst_range_t *asn1constraint_compute_PER_range(asn1p_expr_type_e expr_type,
	const asn1p_constraint_t *ct,
	enum asn1p_constraint_type_e required_type,
	const asn1cnst_range_t *minmax,
	int *expectation_met);
void asn1constraint_range_free(asn1cnst_range_t *);

/*
 * Check that a specific constraint is compatible
 * with the given expression type.
 */
int asn1constraint_compatible(asn1p_expr_type_e expr_type,
	enum asn1p_constraint_type_e constr_type);

/*
 * Fetch a default alphabet for this type.
 */
asn1cnst_range_t *asn1constraint_default_alphabet(asn1p_expr_type_e expr_type);

#endif	/* ASN1FIX_CRANGE_H */