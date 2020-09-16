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
  char s[] = "word ";
  char *t = word_terminator(&s[0]);
  printf("After Word Terminate %s\n",&t[0]);
  //printf("%d\n", *t == '\0');
  //int i = count_words(&s[0]);
  
  
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
  while(! space_char(*word++))
	;
  return word;
}

int count_words(char *str){
  printf("Be foreloop: %s\n", &str[0]);// TODO: Delete Later
  while(*str != '\0' ){
    str = word_start(&str[0]);
    printf("%s\n", &str[0]);
  }
  return 0;
}
