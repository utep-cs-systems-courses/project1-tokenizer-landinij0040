#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAXWORD 100


int space_char(char c);
int non_space_char(char c);
char *word_start(char *str);
int count_words(char *str);
int main()
{
  // char s[50];
  // printf(">");
  // scanf("%[^\n]",s);
  // printf("%s",   s);
  char s[] = "Hello world string";
  tokenize(s);

  return 0;
  

  return 0;
}

/* true if c is a tab or space */
int space_char(char c)
{
  if((c == '\t' || c == ' ') && c != '\0')
    return 1;
  else
    return 0;
}
/* true if c is a NON tab or space */
int non_space_char(char c)
{
  if((c != '\t' && c != ' ') && c != '\0'){
    return 1;
  }else{
    return 0;
  }
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  /* for loop to traverse to word start */
  for(; *str != '\0'; str++ ){
    /* word start found, break loop */
    if(non_space_char(*str)){
      break;
    }
  }
  return str;
}
char *word_terminator(char *word)
{
  for(; *word != '\0'; word++){
    if(space_char(*word)){
      break;
    }
  }
  return word;
}

int count_words(char *str){
  int i = 0;
  while( (*str != '\0')){
    i++;
    str = word_start(     &str[0]);
    str = word_terminator(&str[0]);
  }
  return i;
}

char *copy_str(char *inStr, short len)
{
  // Allocating String
  char *allocedStr = malloc(len * sizeof(char) + 1);

  // Putting input string into allocated string
  for(int i = 0; i < len; i++ ){
    allocedStr[i] = inStr[i];
  }

  // Expliclty putting the zero terminator at the end of the char string
  allocedStr[len] = '\0';

  return allocedStr;
}

char **tokenize(char *str)
{
  // Make Return Pointer That Points to a Pointer
  char **tokVect;

  // While loop till found Zero Terminator
  while(*str != '\0'){
    
  }
}
