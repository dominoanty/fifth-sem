
%{
  #include<stdio.h>
  #define VALID 0
  #define INVALID 1
  int valid_identifier=INVALID;
%}

%%
[a-z]([a-z]|[_]|[0-9])* printf("Valid identifier");
.* printf("Invalid identifier");
%%

main()
{
  printf(" Enter the string : ");
  yylex();
}
