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
%%
(auto|double|int|struct) {/*'*/
				printf("%d: KW_%s\n", line_no, yytext);}
(break|else|long|switch) {printf("%d: KW_%s\n", line_no, yytext);}
(case|enum|register|typedef) {printf("%d: KW_%s\n", line_no, yytext);}
(char|extern|return|union) {printf("%d: KW_%s\n", line_no, yytext);}
(const|float|short|unsigned) {printf("%d: KW_%s\n", line_no, yytext);}
(continue|for|signed|void) {printf("%d: KW_%s\n", line_no, yytext);}
(default|goto|sizeof|volatile) {printf("%d: KW_%s\n", line_no, yytext);}
(do|if|static|while) {printf("%d: KW_%s\n", line_no, yytext);}

(\+|\-|\*|\&|\~|\!|\/|\%|\<|\>|\||\^|\=|\,|\.|\?) {printf("%d: OP_%s\n", line_no, opname[yytext[0]]);}
"++" {printf("%d: OP_INCR\n", line_no);}
"--" {printf("%d: OP_DECR\n", line_no);}
"<<" {printf("%d: OP_LSHIFT\n", line_no);}
">>" {printf("%d: OP_RSHIFT\n", line_no);}
"<=" {printf("%d: OP_LTE\n", line_no);}
">=" {printf("%d: OP_GTE\n", line_no);}
"==" {printf("%d: OP_EQ\n", line_no);}
"!=" {printf("%d: OP_NEQ\n", line_no);}
"&&" {printf("%d: OP_LOGAND\n", line_no);}
"||" {printf("%d: OP_LOGOR\n", line_no);}
"+=" {printf("%d: OP_PLUSEQ\n", line_no);}
"/=" {printf("%d: OP_DIVEQ\n", line_no);}
"%=" {printf("%d: OP_MODEQ\n", line_no);}
"-=" {printf("%d: OP_MINUSEQ\n", line_no);}
"*=" {printf("%d: OP_MULEQ\n", line_no);}
"<<=" {printf("%d: OP_LSHIFTEQ\n", line_no);}
">>=" {printf("%d: OP_RSHIFTEQ\n", line_no);}
"|=" {printf("%d: OP_OREQ\n", line_no);}
"&=" {printf("%d: OP_ANDEQ\n", line_no);}
"^=" {printf("%d: OP_XOREQ\n", line_no);}
"->" {printf("%d: OP_DEREF\n", line_no);}

"{"|"}"|"["|"]"|"("|")"|";"|":" {printf("%d: PUNC_%s\n", line_no, opname[yytext[0]]);}

[a-zA-Z_][a-zA-Z_0-9]* {printf("%d: IDENTIFIER %s\n", line_no, yytext);}


{NUMBER} {printf("%d: NUMBER %s\n", line_no, yytext);}
{REAL} {printf("%d: REAL_NUMBER %s\n", line_no, yytext);}
{EXP} {printf("%d: EXP_NUMBER %s\n", line_no, yytext);}
{CHAR} {printf("%d: CHAR_CONSTANT %s\n", line_no, yytext);}
\"([^"\\]|\\.)*\" {printf("%d: STRING_CONSTANT %s\n", line_no, yytext);}

. {}
\n {line_no++;}
%%
int yywrap(){/*"*/
	return -1;
}
int main(int argc, char *argv[]){
	opname['+'] = "PLUS";
	opname['-'] = "MINUS";
	opname['&'] = "AMP";
	opname['*'] = "STAR";
	opname['~'] = "COMP";
	opname['!'] = "NEGATE";
	opname['/'] = "DIV";
	opname['%'] = "MOD";
	opname['<'] = "LT";
	opname['>'] = "GT";
	opname['|'] = "BITOR";
	opname['^'] = "BITXOR";
	opname['='] = "ASSIGN";
	opname[','] = "COMMA";
	opname['.'] = "DOT";
	opname['{'] = "OPBRACE";opname['}'] = "CLOSEBRACE";
	opname['['] = "OPSQRBKT";opname[']'] = "CLOSESQRBKT";
	opname['('] = "OPBKT";opname[')'] = "CLOSEBKT";
	opname[';'] = "SEMICOLON";opname[':'] = "COLON";
	opname['?'] = "QUES";
	if(argc < 2){
		printf("Error!\n");
		return -1;
	}
	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");
	yylex();
	fclose(yyin);
	fclose(yyout);
}
