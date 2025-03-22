#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 5
#define inf -1

#define final(v, t) (v == t) ? true : false

// todo later on
typedef struct Vertex {
  int id;
  int x;
  int y;
} Vertex;

Vertex vertex[n] = {{.id = 0, .x = 0, .y = 2},
                    {.id = 1, .x = 8, .y = 8},
                    {.id = 2, .x = 5, .y = 1},
                    {.id = 3, .x = 5, .y = 6},
                    {.id = 4, .x = 1, .y = 9}};

int Weights[5][5] = {{0, 7, 0, 15, 0},
                     {12, 0, 9, 0, 0},
                     {0, 6, 0, 0, 23},
                     {18, 0, 0, 0, 19},
                     {0, 0, 11, 14, 0}};

int *res;
int *dist;
bool visited[n];
int *pai;

void init() {
  res = malloc(sizeof(int) * n);
  res[0] = 0;
  for (int i = 1, j = 0; i < n; i++, j++) {
    res[i] = inf;
  }
};

void print() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d\t", Weights[i][j]);
    }
    puts("");
  }
}

void minimum_dist() {
  int min;
  int minIndex;

  for (int i = 0; i < n; i++) {
    if (visited[i] == false && dist[i] <= min) {
      min = dist[i];
      minIndex = i;
    }
  }
}

int *find_shortest_path(int s, int t) {
  if (final(vertex[s].id, vertex[t].id))
    return res;

  return res;
}

void print_res(int *res) {
  if (!res)
    return;

  for (int i = 0; i < n; i++)
    printf("-> %d ", res[i]);
  puts("");
  free(res);
}

int main(int argc, char **argv) {
  init();
  print();

  srand(time(NULL));
  int a = rand() % n;
  int b = rand() % n;
  b = b == a ? (a + 1) % 4 : b;

  if (a > b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
  }

  puts("");
  printf("finding path from %d %d\n", a, b);
  puts("");

  res = find_shortest_path(vertex[1].id, vertex[4].id);
  print_res(res);
  return 0;
}
