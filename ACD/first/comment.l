
%{
  #include<stdio.h>
%}

%%
[/][/].* printf("Comment : %s ", yytext);
[/][*][^*]*[*][/] printf("Comment %s ", yytext);
.* printf("Not comment %s", yytext);
%%

main()
{
  printf(" Enter the string : ");
  yyin = fopen("input.txt","r");
  yylex();
}
