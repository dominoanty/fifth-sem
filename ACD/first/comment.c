#include <stdio.h>
#include <string.h>
void print_state(int state)
{
  switch(state)
  {
    case 0: printf("OTHER");
            break;
    case 1: printf("COMMENT_START_START");
            break;
    case 2: printf("COMMENT_START");
            break;
    case 3: printf("COMMENT_END_START");
            break;
    case 4: printf("COMMENT_END_END");
            break;


  }
}
void main()
{
  enum states{ OTHER, COMMENT_START_START, COMMENT_START, COMMENT_END_START, COMMENT_END_END};
  int current_state = OTHER;
  int i=0;
  char line[30];
  fgets(line, 30, stdin);
  for(i=0; line[i] != '\0';i++)
  {
    //printf("\n Character %c current state : ", line[i]);
    //print_state(current_state);
    if(current_state == OTHER)
    {
      if(line[i] == '/')
      {
        current_state = COMMENT_START_START;
      }
      continue;
    }
    if(current_state == COMMENT_START_START)
    {
      if(line[i] == '/')
      {
          current_state = COMMENT_END_END;
          break;
      }
      else if(line[i] == '*')
        current_state = COMMENT_START;
      else
        current_state = OTHER;
      continue;
    }
    if(current_state == COMMENT_START)
    {
      if(line[i] == '*')
      {
      //  printf("\nReached the end of comment");
        current_state = COMMENT_END_START;
      }
      continue;
    }
    if(current_state == COMMENT_END_START)
    {
      if(line[i] == '/')
        current_state = COMMENT_END_END;
      else
        current_state = COMMENT_START;
      continue;
    }

  }

  if(current_state != COMMENT_END_END)
    printf("\nLine is not a comment ");
  else
    printf("\n Line is a comment");
  printf("\n");
}

