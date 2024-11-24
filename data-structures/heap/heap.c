#include "heap.h"

int father(int i) { return i / 2; }
int lchild(int i) { return 2 * i + 1; }
int rchild(int i) { return (2 * i) + 2; }
int root(heap A) { return A.arr[0]; }

void max_heapify(heap *A, int n) {
  A->n = A->length;
  for (int i = n / 2; i > 0; i--)
    max_heap(A, i);
}

void max_heap(heap *A, int i) {
  int l = lchild(i);
  int r = rchild(i);
  int maior = 0;

  if (l <= A->n && A->arr[l] > A->arr[i])
    maior = l;
  if (r <= A->n && A->arr[r] > A->arr[maior])
    maior = r;
  if (maior != i) {
    swap(A->arr[i], A->arr[maior]);
    max_heapify(A, maior);
  }
}

heap *build_max_heap(int length, int *arr) {
  int i;
  heap *h = (heap *)malloc(sizeof(heap));

  if (!h) {
    puts("Memory error");
    return NULL;
  }

  h->n = 0;
  h->length = length;
  h->arr = (int *)malloc(length * sizeof(int));

  if (h->arr == NULL) {
    printf("Memory error");
    return NULL;
  }

  for (i = 0; i < length; i++) {
    h->arr[i] = arr[i];
  }

  h->n = i;
  i = (h->n - 2) / 2;
  while (i >= 0) {
    max_heapify(h, i);
    i--;
  }
  return h;
}

void insert(heap *h, int data) {
  if (h->n < h->length) {
    h->arr[h->n] = data;
    max_heapify(h, h->n);
    h->n++;
  }
}

void delete(heap *h) {
  int aux;
  if (h->n == 0) {
    puts("Heap id empty.");
    return;
  }

  aux = root(*h);
  h->arr[0] = h->arr[h->n - 1];
  h->n--;
  max_heapify(h, 0);
}

void heap_sort(heap *A) {
  for (int i = A->length; i > 1; i--) {
    swap(A->arr[i], A->arr[0]);
    A->n--;
    max_heapify(A, 1);
  }
}
