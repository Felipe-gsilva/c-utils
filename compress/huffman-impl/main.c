#include "stdio.h"
#include "stdlib.h"
#include "queue.h"
#include "tree.h"

int main(int argc, char *argv[]) {
  FILE *in;
  queue *Q = malloc(sizeof(queue));
  tree T;
  

  if((in = fopen("file.txt", "r")) == NULL)
    exit(1);

  char c;
  while ((c = fgetc(in)) != EOF) {
    push(Q, new_node(c)); 
  } 

  print(Q);
  cleanup(Q);
  free(Q);

  fclose(in);
  return 0;
}

// TODO
void encode();
void decode();
