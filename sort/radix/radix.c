#include "radix.h"

void counting_sort_for_radix(int *arr, int n, int exp) {
  int b[n];
  int c[10] = {0};

  for (int i = 0; i < n; i++)
    c[(arr[i] / exp) % 10]++;

  for (int i = 1; i < 10; i++)
    c[i] += c[i - 1];

  for (int i = n - 1; i >= 0; i--) {
    b[c[(arr[i] / exp) % 10] - 1] = arr[i];
    c[(arr[i] / exp) % 10]--;
  }

  for (int i = 0; i < n; i++)
    arr[i] = b[i];
}

void radix_sort(int *arr, int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > max)
      max = arr[i];

  for (int i = 1; max / i > 0; i *= 10)
    counting_sort_for_radix(arr, n, i);
}
