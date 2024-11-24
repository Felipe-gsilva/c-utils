#include <stdio.h>

#ifdef _queue_
#define _queue_
#else
typedef struct queue{
  char c;
  int freq;
  struct queue *next;
} queue;

queue* new_node(char c);
void push(queue* head, queue* node);
queue* cleanup(queue* head);
void print(queue *head);

#endif
