#include "counting.h"

void counting_sort(int *arr, int n, int max) {
  int b[n];       
  int c[max + 1]; 

  for (int i = 0; i <= max; i++)
    c[i] = 0;

  for (int i = 0; i < n; i++)
    c[arr[i]]++;

  for (int i = 1; i <= max; i++)
    c[i] += c[i - 1];

  for (int i = n - 1; i >= 0; i--) {
    b[c[arr[i]] - 1] = arr[i];
    c[arr[i]]--;
  }

  for (int i = 0; i < n; i++)
    arr[i] = b[i];
}
