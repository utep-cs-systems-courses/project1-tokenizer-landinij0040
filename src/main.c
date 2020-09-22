#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  // Variable used to exit the while loop
  int whileChecker = 1;

  // Make Linked List
  List *linked_list = init_history();

  // The menu
  while(whileChecker){
    char s[50];
    // Instructions
    printf("PRESS:\n");
    printf("!q to quit:\n");
    printf("!h to view your history\n");
    printf("!<number> to pick a specific history node\n");
    printf("Enter your string otherwise\n\n");
    printf(">");
    scanf("%[^\n]",s);
    // To clear the buffer
    while((getchar()) != '\n');
    if(*s == '!'){ // Special key word
      if(*(s+1) == 'q' ){ // Quit the program
	// Making whileChecker 0 to exit program
	whileChecker = 0;
	// Freeing the history
	free_history(linked_list);
      }else if(*(s+1) == 'h'){ // Print what is inside the history
	print_history(linked_list);
	
      }else{ // Get history at specific node
	int number = atoi(s+1);
	char *gotString = get_history(linked_list, number);
	//TODO: Print the string from reterive histroy here
	printf("%s\n",gotString);
	//TODO: Tokenize the string here
	char **token = tokenize(gotString);
	//TODO: Print the tokenized string here
	print_tokens(token);
	//TODO: Free the vector
	free_tokens(token);
      }
    }else{
      printf("%s\n",s);
      printf("--------\n");
      char **token = tokenize(s);
      print_tokens(token);
      printf("\n");
      free_tokens(token);
      add_history(linked_list, s);
      
    }
  }
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
  // Amount of words in the string
  int amountWords = count_words(str);
  
  // Make Return Pointer That Points to a Pointer
  char **tokVect = malloc(sizeof(char *) * (amountWords + 1));

  // Make ending Pointer for passing how long a word in the string is
  char *end;
  
  for(int i = 0; i < amountWords; i++){
    str = word_start(str);
    end = word_terminator(str);
    tokVect[i] = copy_str(str, end - str);
    str = end;
  }
  tokVect[amountWords] = NULL;

  return tokVect;
}

void print_tokens(char **tokens)
{
  do{
    printf("%s\n", *tokens++);
  }while(*tokens != NULL );  
}

void free_tokens(char **tokens)
{
  int i = 0;
  do{
    free(*(tokens + i));
    i++;
  }while(*(tokens + i) != NULL);
  free(*(tokens + i));
  
  free(tokens);
}
