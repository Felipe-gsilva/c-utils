#include "queue.h"
#include "stdlib.h"

queue* new_node(char c) {
  queue* node = malloc(sizeof(queue));
  node->c = c;
  node->freq = 1;
  node->next = NULL;
  printf("new node created with char:%c\n", node->c);
  return node;
}

void push(queue* head, queue* node) {
  queue *aux = head;
  while(aux->c != node->c && aux->next != NULL) {
    aux = aux->next;
  }

  if(aux->c == node->c) {
    aux->freq++;
    return;
  }

  aux->next = node;
}


queue *cleanup(queue *node) {
  if(node->next == NULL) {
    free(node);
  }
  return cleanup(node->next); 
}

void print(queue *head) {
  queue *aux = head;
  while(aux->next != NULL) {
    printf("freq: %d c: %c\n", aux->freq, aux->c);
    aux = aux->next;
  }
}
