#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void main()
{
  char input_string[20];
  char *keyword_list[] = { "auto"  ,"double","int","struct","break","else","long","switch","case","enum","register","typedef","char","extern","return","union","const","float","short","unsigned","continue","for","signed","void","default","goto","sizeof","volatile","do","if","static","while"};
  int i=0;
  
  printf("\nEnter identifier to check : ");
  fgets(input_string, sizeof(input_string), stdin);

  for(i=0; i<32; i++)
  {
    if(!strncmp(keyword_list[i], input_string,strlen(keyword_list[i])))
    {
      printf("\nInvalid identifier");
      exit(0);
    }
  }
  for(i=0; input_string[i] != '\0' && input_string[i] != '\n'; i++)
  {
    if(i==0)
    {
      if(!isalpha(input_string[i]))
      {
        printf("\nInvalid identifier");
        exit(0);
      }
    }
    else
    {
      if(!isalnum(input_string[i]) && input_string[i] != '_')
      {
        printf("\nInvalid identifier");
        exit(0);
      }
    }
  }
  printf("\n Valid identifier");
}
