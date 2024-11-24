#include "usual_fns.h"

int max(int a, int b) { return a > b ? a : b; }

void swap(int a, int b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
