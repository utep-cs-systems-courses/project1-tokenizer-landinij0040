#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history()
{
  List *linked_list = malloc(sizeof(List));
  return linked_list;
}

/*Add history to the linked_list*/
void add_history(List *list, char *str)
{
  int id_number = 1;
  if((list -> root) == NULL){ // No Nodes in Linked list
    // Allocating the first node
    Item *node = malloc(sizeof(Item));
    // Putting the id number on the first node
    node -> id = id_number;
    // Putting the string into the first node
    node -> str = str;
    // Putting the first node as the root
    list -> root = node;
  } else{ // Adding nodes to end of list.
    // Making node to traverse through list
    Item *node = list -> root;
    // Making the new node  
    Item *newNode = malloc(sizeof(Item));
    // Starting at id 2
    id_number++;
    // traverse till found last node
    while((node -> next) != NULL){
      id_number++;
      node = node -> next; 
    }
    // Make insert into newNode's members
    newNode -> id = id_number;
    newNode -> str = str;
    // Linking to prev node
    node -> next = newNode;
  }
}

char *get_history(List *list, int id)
{
  int currentNodeId = 1;
  Item *item = list -> root;
  while((item -> next) != NULL){
    if(currentNodeId == id){
      break;
    }
    item = item -> next;
    currentNodeId++;
  }
  return item -> str;


}

void print_history(List *list)
{
  Item *node = list -> root;
  while(node != NULL){
    printf("%d. %s\n",node->id, node->str);
    node = node -> next;
  }

}

void recursive_free_node(Item *node)
{
  printf("in the recursive function%d\n", node -> id);
  if((node -> next) == NULL){
    free(node);
    return ;
  }
  recursive_free_node(node -> next);
  free(node);
}

void free_history(List *list)
{
  Item *node = list -> root;
  recursive_free_node(node);
  free(list);

}

