#include <limits.h>
#include <stdio.h>
#include <string.h>

// Função recursiva para o problema de corte de hastes
int corta_haste(int p[], int n) {
  if (n == 0)
    return 0;

  int q = INT_MIN;
  for (int i = 1; i <= n; i++) {
    q = (q > p[i - 1] + corta_haste(p, n - i))
            ? q
            : (p[i - 1] + corta_haste(p, n - i));
  }

  return q;
}

typedef struct {
  int m;
  int i;
} answer;

answer *corta_haste_memoizado(int p[], int c[], int n, answer m[]) {
  if (m[n].m >= 0)
    return m;

  if (n == 0) {
    m[n].m = 0;
    m[n].i = -1;
    return m;
  }

  int q = INT_MIN;
  for (int i = 1; i <= n; i++) {
    int valor =
        p[i - 1] - c[i - 1] + (corta_haste_memoizado(p, c, n - i, m))->m;
    if (valor > q) {
      q = valor;
      m[n].i = i;
    }
  }

  m[n].m = q;
  return m;
}

void print_answer(answer m[], int n) {
  printf("Cuts: ");
  while (n > 0) {
    printf("%d ", m[n].i);
    n -= m[n].i;
  }
  printf("\n");
}

// int main() {
//   int preco[] = {1, 5, 8, 9, 10, 17, 17, 20};
//   int custo[] = {1, 1, 2, 3, 4, 50, 1, 50};
//   int n = sizeof(preco) / sizeof(preco[0]);
//
//   answer m[n + 1];
//   for (int i = 0; i <= n; i++) {
//     m[i].m = -1;
//     m[i].i = -1;
//   }
//
//   corta_haste_memoizado(preco, custo, n, m);
//   printf("Lucro máximo: %d\n", m[n].m);
//   print_answer(m, n);
//
//   return 0;
// }

int f(int i, answer m[]) {
  if (m[i].m > -1)
    return m[i].m;

  if (i == 0)
    return 0;

  if (i == 1)
    return 1;

  int return_f = f(i - 2, m) + f(i - 1, m);
  m[i].m = return_f;
  return return_f;
}

#define fib_num 30
int main() {
  answer m[fib_num + 1];
  memset(m, -1, sizeof(m));
  printf("fib de %d: %d\n", fib_num, f(fib_num, m));
  return 0;
}
