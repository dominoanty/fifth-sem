/*Program to count the number of characters, words, spaces, end of
lines in a given input file.*/

%{
#include<stdio.h>
#include<stdlib.h>
int lines=0, words=0,s_letters=0,c_letters=0, num=0, spl_char=0,total=0;
%}
                                 /*end of definition*/ 
%%
                                 /* the prinf of the rules can be written without {} if its a single variable*/
\n { lines++; words++;}
[\t ' '] words++;
[A-Z] c_letters++;
[a-z] s_letters++;
[0-9] num++;
. spl_char++;
%%
//c code
main(int argc, char *argv[])
{
  if(argc != 2)
  {
    printf("Usage: %s filename", argv[0]);
    exit(0);
  }
  yyin= fopen(argv[1],"r");          /* You can use different methods to input file*/
  yylex();
  total=s_letters+c_letters+num+spl_char;
  printf(" This File contains ...");
  printf("\n\t%d lines", lines);
  printf("\n\t%d words",words);
  printf("\n\t%d small letters", s_letters);
  printf("\n\t%d capital letters",c_letters);
  printf("\n\t%d digits", num);
  printf("\n\t%d special characters",spl_char);
  printf("\n\tIn total %d characters.\n",total);
}
int yywrap()
{
  return(1);
}                                 /*optional*/
