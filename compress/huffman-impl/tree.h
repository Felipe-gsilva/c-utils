#include <stdio.h>

#ifdef _tree_
#define _tree_
#else
typedef struct tree {
  char l;
  struct tree *left;
  struct tree *right;
} tree;

#endif
