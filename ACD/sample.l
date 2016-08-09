%{
  #include<stdio.h>
  int count1=0;
  int count2=0;
%}

%%
[AEIOUaeiou] {printf("\n %s is vowel",yytext);count1++;}
[a-zA-Z] {printf("\n %s is constonant",yytext);count2++;}
%%

main()
{
  printf(" Enter the sring ( note press ctrl d to end program) :");
  yylex();
  printf(" %d Vowel \n %d constonant",count1,count2);
}
