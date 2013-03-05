#define ID 257
#define INTVAL 258
#define VOID 259
#define CHAR 260
#define SHORT 261
#define INT 262
#define LONG 263
#define FLOAT 264
#define DOUBLE 265
#define PTR 266
#define STATIC 267
#define RETURN 268
#define WHILE 269
#define SWITCH 270
#define DEFAULT 271
#define ELSE 272
#define BREAK 273
#define DO 274
#define FOR 275
#define CASE 276
#define IF 277
#define CONTINUE 278
#define GOTO 279
#define UNSIGNED 280
#define CONST 281
#define EXTERN 282
#define REGISTER 283
#define TYPEDEF 284
#define UNION 285
#define AUTO 286
#define PREPROC 287
#define FLTVAL 288
#define DBLVAL 289
#define STRVAL 290
#define CHARVAL 291
#define SEMICOLON 292
#define LEFTPAREN 293
#define RIGHTPAREN 294
#define LEFTBRACKET 295
#define RIGHTBRACKET 296
#define RIGHTSQRBRACK 297
#define LEFTSQRBRACK 298
#define COMMA 299
#define AND 300
#define OR 301
#define PLUSEQ 302
#define DIVEQ 303
#define ANDEQ 304
#define RIGHTSHIFTEQ 305
#define STRUCT 306
#define SIZEOF 307
#define BITSHIFTRIGHTEQ 308
#define SUBEQ 309
#define MODEQ 310
#define XOREQ 311
#define GTEQ 312
#define MULTEQ 313
#define OREQ 314
#define BITSHIFTLEFTEQ 315
#define BITSHIFTLEFT 316
#define BITSHIFTRIGHT 317
#define BITSHIFTR 318
#define BITSHIFTL 319
#define GTE 320
#define LTE 321
#define EQ 322
#define NOTEQ 323
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    char* id;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
