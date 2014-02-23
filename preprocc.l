%{
%}
%%
\\\n {}
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
