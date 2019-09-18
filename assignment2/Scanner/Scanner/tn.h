/*
tokentypes.h- 토큰들의 종류를 Enum으로 선언한 헤더.
programmer-이경연, 박소현
date-19.04.26
*/
enum tokentypes {

	TEOF,

	TCONST, TELSE, TIF, TINT, TRETURN, TVOID, TWHILE,

	TPLUS, TMINUS, TMUL, TDIV, TPERCENT,

	TADDASSIGN, TSUBASSIGN, TMULASSIGN, TDIVASSIGN, TMODASSIGN, TASSIGN,

	TNOT, TAND, TOR,

	TEQUAL, TNOTEQU, TLESS, TGREAT, TEQLESS, TEQGREAT,

	TINC, TDEC,


	TNEWLINE, TBLANK, TTAB,

	TBIGBRACE_L, TBIGBRACE_R, TMIDBRACE_L, TMIDBRACE_R, TSMALLBRACE_L, TSMALLBRACE_R,
	TCOLON,

	TIDENT, TSEMICOLON, TSTRING, TCHAR,


	TNUMBER, TREAL, TOCTA, THEXA,

	TERROR_DIGIT_START, TERROR_ILL_CHAR_1, TERROR_ILL_CHAR_2, TLONGERR, TERROR
};
