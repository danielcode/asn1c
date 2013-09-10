#ifndef EXPR_TYPES_H
#define EXPR_TYPES_H

/*
 * ASN type of the expression.
 */
typedef enum asn1_expr_type {
	/*
	 * ASN.1 Constructed types
	 */
	ASN1_TYPE_SEQUENCE = 0x20,
	ASN1_TYPE_CHOICE,
	ASN1_TYPE_SET,
	ASN1_TYPE_SEQUENCE_OF,
	ASN1_TYPE_SET_OF,

	/*
	 * ASN.1 Basic types
	 */
	ASN1_TYPE_ANY = 0x40,
	ASN1_TYPE_BOOLEAN,
	ASN1_TYPE_NULL,
	ASN1_TYPE_INTEGER,
	ASN1_TYPE_REAL,
	ASN1_TYPE_ENUMERATED,
	ASN1_TYPE_BIT_STRING,
	ASN1_TYPE_OCTET_STRING,
	ASN1_TYPE_OBJECT_IDENTIFIER,
	ASN1_TYPE_RELATIVE_OID,
	ASN1_TYPE_EXTERNAL,
	ASN1_TYPE_EMBEDDED_PDV,
	ASN1_TYPE_CHARACTER_STRING,
	ASN1_TYPE_UTCTime,
	ASN1_TYPE_GeneralizedTime,

	/*
	 * ASN.1 String types
	 */
	ASN1_TYPE_IA5String = 0x100,
	ASN1_TYPE_PrintableString,
	ASN1_TYPE_VisibleString,
	ASN1_TYPE_ISO646String,
	ASN1_TYPE_NumericString,
	ASN1_TYPE_UniversalString,
	ASN1_TYPE_BMPString,
	ASN1_TYPE_UTF8String = 0x200,
	ASN1_TYPE_GeneralString,
	ASN1_TYPE_GraphicString,
	ASN1_TYPE_TeletexString,
	ASN1_TYPE_T61String,
	ASN1_TYPE_VideotexString,
	ASN1_TYPE_ObjectDescriptor,
} asn1_expr_type_e;

#endif
