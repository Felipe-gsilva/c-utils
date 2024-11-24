#ifndef _HEAP
#define _HEAP

#include "stdio.h"
#include "stdlib.h"
#include "../../utils/usual_fns.h"

typedef struct heap heap;

struct heap {
  int *arr;
  int n;
  int length;
};

int father(int i);
int lchild(int i);
int rchild(int i);
int root(heap A);
void max_heapify(heap *A, int n);
void max_heap(heap *A, int i);

#endif
