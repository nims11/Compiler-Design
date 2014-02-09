%{
	//How to handle Ternary Operator, Subscript Operator, typecast
	//Sizeof KW vs OP?
	int line_no = 1;
	const char *opname[128];

%}
NUMBER 0|([1-9][0-9]*)
REAL ([0-9]*\.[0-9]+)|([0-9]+\.[0-9]*)
EXP ({REAL}|{NUMBER})[eE][+-]?[0-9]+
CHAR \'([^'\\]|\\.)*\'

%option noyywrap
%%
auto {printf("%d: KW_auto\n",line_no);return KW_auto;}
double {printf("%d: KW_double\n",line_no);return KW_double;}
int {printf("%d: KW_int\n",line_no);return KW_int;}
struct {printf("%d: KW_struct\n",line_no);return KW_struct;}
break {printf("%d: KW_break\n",line_no);return KW_break;}
else {printf("%d: KW_else\n",line_no);return KW_else;}
long {printf("%d: KW_long\n",line_no);return KW_long;}
switch {printf("%d: KW_switch\n",line_no);return KW_switch;}
case {printf("%d: KW_case\n",line_no);return KW_case;}
enum {printf("%d: KW_enum\n",line_no);return KW_enum;}
register {printf("%d: KW_register\n",line_no);return KW_register;}
typedef {printf("%d: KW_typedef\n",line_no);return KW_typedef;}
char {printf("%d: KW_char\n",line_no);return KW_char;}
extern {printf("%d: KW_extern\n",line_no);return KW_extern;}
return {printf("%d: KW_return\n",line_no);return KW_return;}
union {printf("%d: KW_union\n",line_no);return KW_union;}
const {printf("%d: KW_const\n",line_no);return KW_const;}
float {printf("%d: KW_float\n",line_no);return KW_float;}
short {printf("%d: KW_short\n",line_no);return KW_short;}
unsigned {printf("%d: KW_unsigned\n",line_no);return KW_unsigned;}
continue {printf("%d: KW_continue\n",line_no);return KW_continue;}
for {printf("%d: KW_for\n",line_no);return KW_for;}
signed {printf("%d: KW_signed\n",line_no);return KW_signed;}
void {printf("%d: KW_void\n",line_no);return KW_void;}
default {printf("%d: KW_default\n",line_no);return KW_default;}
goto {printf("%d: KW_goto\n",line_no);return KW_goto;}
sizeof {printf("%d: KW_sizeof\n",line_no);return KW_sizeof;}
volatile {printf("%d: KW_volatile\n",line_no);return KW_volatile;}
do {printf("%d: KW_do\n",line_no);return KW_do;}
if {printf("%d: KW_if\n",line_no);return KW_if;}
static {printf("%d: KW_static\n",line_no);return KW_static;}
while {printf("%d: KW_while\n",line_no);return KW_while;}

"+" {printf("%d: OP_PLUS\n",line_no);return OP_PLUS;}
"-" {printf("%d: OP_MINUS\n",line_no);return OP_MINUS;}
"*" {printf("%d: OP_STAR\n",line_no);return OP_STAR;}
"&" {printf("%d: OP_AMP\n",line_no);return OP_AMP;}
"~" {printf("%d: OP_COMP\n",line_no);return OP_COMP;}
"!" {printf("%d: OP_NEGATE\n",line_no);return OP_NEGATE;}
"/" {printf("%d: OP_DIV\n",line_no);return OP_DIV;}
"%" {printf("%d: OP_MOD\n",line_no);return OP_MOD;}
"<" {printf("%d: OP_LT\n",line_no);return OP_LT;}
">" {printf("%d: OP_GT\n",line_no);return OP_GT;}
"|" {printf("%d: OP_BITOR\n",line_no);return OP_BITOR;}
"^" {printf("%d: OP_BITXOR\n",line_no);return OP_BITXOR;}
"=" {printf("%d: OP_ASSIGN\n",line_no);return OP_ASSIGN;}
"," {printf("%d: OP_COMMA\n",line_no);return OP_COMMA;}
"." {printf("%d: OP_DOT\n",line_no);return OP_DOT;}
"?" {printf("%d: OP_QUES\n",line_no);return OP_QUES;}
"++" {printf("%d: OP_INCR\n",line_no);return OP_INCR;}
"--" {printf("%d: OP_DECR\n",line_no);return OP_DECR;}
"<<" {printf("%d: OP_LSHIFT\n",line_no);return OP_LSHIFT;}
">>" {printf("%d: OP_RSHIFT\n",line_no);return OP_RSHIFT;}
"<=" {printf("%d: OP_LTE\n",line_no);return OP_LTE;}
">=" {printf("%d: OP_GTE\n",line_no);return OP_GTE;}
"==" {printf("%d: OP_EQ\n",line_no);return OP_EQ;}
"!=" {printf("%d: OP_NEQ\n",line_no);return OP_NEQ;}
"&&" {printf("%d: OP_LOGAND\n",line_no);return OP_LOGAND;}
"||" {printf("%d: OP_LOGOR\n",line_no);return OP_LOGOR;}
"+=" {printf("%d: OP_PLUSEQ\n",line_no);return OP_PLUSEQ;}
"/=" {printf("%d: OP_DIVEQ\n",line_no);return OP_DIVEQ;}
"%=" {printf("%d: OP_MODEQ\n",line_no);return OP_MODEQ;}
"-=" {printf("%d: OP_MINUSEQ\n",line_no);return OP_MINUSEQ;}
"*=" {printf("%d: OP_MULEQ\n",line_no);return OP_MULEQ;}
"<<=" {printf("%d: OP_LSHIFTEQ\n",line_no);return OP_LSHIFTEQ;}
">>=" {printf("%d: OP_RSHIFTEQ\n",line_no);return OP_RSHIFTEQ;}
"|=" {printf("%d: OP_OREQ\n",line_no);return OP_OREQ;}
"&=" {printf("%d: OP_ANDEQ\n",line_no);return OP_ANDEQ;}
"^=" {printf("%d: OP_XOREQ\n",line_no);return OP_XOREQ;}
"->" {printf("%d: OP_DEREF\n",line_no);return OP_DEREF;}
"..." {printf("%d: OP_ELLIPSIS\n",line_no);return OP_ELLIPSIS;}


"{" {printf("%d: PUNC_OPBRACE\n",line_no);return PUNC_OPBRACE;}
"}" {printf("%d: PUNC_CLOSEBRACE\n",line_no);return PUNC_CLOSEBRACE;}
"[" {printf("%d: PUNC_OPSQRBKT\n",line_no);return PUNC_OPSQRBKT;}
"]" {printf("%d: PUNC_CLOSESQRBKT\n",line_no);return PUNC_CLOSESQRBKT;}
"(" {printf("%d: PUNC_OPBKT\n",line_no);return PUNC_OPBKT;}
")" {printf("%d: PUNC_CLOSEBKT\n",line_no);return PUNC_CLOSEBKT;}
";" {printf("%d: PUNC_SEMICOLON\n",line_no);return PUNC_SEMICOLON;}
":" {printf("%d: PUNC_COLON\n",line_no);return PUNC_COLON;}

[a-zA-Z_][a-zA-Z_0-9]* {printf("%d: IDENTIFIER %s\n", line_no, yytext); return IDENTIFIER;}

{NUMBER} {printf("%d: NUMBER %s\n", line_no, yytext); return NUMBER;}
{REAL} {printf("%d: REAL_NUMBER %s\n", line_no, yytext); return REAL_NUMBER;}
{EXP} {printf("%d: EXP_NUMBER %s\n", line_no, yytext); return EXP_NUMBER;}
{CHAR} {printf("%d: CHAR_CONSTANT %s\n", line_no, yytext); return CHAR_CONSTANT;}
\"([^"\\]|\\.)*\" {printf("%d: STRING_CONSTANT %s\n", line_no, yytext); return STRING_CONSTANT;}

. {}
\n {line_no++;}
%%