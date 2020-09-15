#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

#define MAXWORD 100
/* true if c is a tab or space, and not zero */
int space_char(char c)
{
  if(c == "\t" || c == " ")
    return 1;
  else
    return 0;



}

int main()
{
  /* To hold value from user */
  char s[MAXWORD];
  printf(">");
  scanf("%[^\n]", &s);
  printf("%s\n",s);
  return 0;
}

