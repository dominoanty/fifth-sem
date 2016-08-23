#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{

  char input_string[20];
  int i=0;
  enum{INIT, B_STATE, DEAD};
  int state = INIT;
  printf("\nInput your string :");
  fgets(input_string, 20, stdin);

  //Check condition 1
  if(i == 0 && input_string[0] == 'a' && (input_string[1] == '\0' || input_string[1] == '\n'))
    {
      printf("\n Found a ");
      exit(0);
      
    }

  //Check condition 2 
  if(input_string[0] == 'a' && input_string[1] == 'b' && input_string[2] == 'b' &&( input_string[3] == '\0' || input_string[3] == '\n'))
  {
    printf("\n Found abb ");
    exit(0);
  }

  //State machine to test for 3 
  for(i=0; input_string[i] != '\0' && input_string[i] != '\n'; i++)
  {
    if(state == DEAD)
    {
      printf("\n No match ");
      exit(0);
    }
    if(state == INIT)
    {
      if(input_string[i] == 'a');
      else if(input_string[i] =='b') state =B_STATE;
      else state=DEAD;
    }
    else if(state == B_STATE)
    {
      if(input_string[i] == 'b') state=B_STATE;
      else state=DEAD;
    }

  }
  if(state == DEAD)
  {
    printf("\n No match ");
    exit(0);
  }
  printf("\nMatched for a*b+ ");
}
