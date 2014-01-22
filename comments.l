%{
	FILE *yyout;
	int single_line = 0, multi_line = 0;
%}
%%

\/\/ {if(!multi_line)single_line = 1;}
\/\* {if(!single_line) multi_line = 1;}
\*\/ {if(!(multi_line || single_line)) fprintf(yyout, "%s", yytext);else multi_line = 0;}
\n {single_line = 0; if(!(multi_line || single_line) || 1) fprintf(yyout, "%s", yytext);}
. {if(!(multi_line || single_line)) fprintf(yyout, "%s", yytext);}
%%
int yywrap(){
	return -1;
}
int main(int argc, char *argv[]){
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
