#include <stdio.h>
#include <time.h>

#ifndef SIZE
#define SIZE 256
#endif

int main(void) {
  int a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE];
  double start, end;

  // initialize
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      a[i][j] = i + j;
      b[i][j] = i - j;
      c[i][j] = 0;
    }
  }

  // computation
  start = (double)clock();

  for (int j = 0; j < SIZE; j++) {
    for (int k = 0; k < SIZE; k++) {
      for (int i = 0; i < SIZE; i++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  end = (double)clock();

  printf("Time : %lf sec\n", (end - start) / CLOCKS_PER_SEC);

  // to avoid wrong optimization
  FILE* dev_null = fopen("/dev/null", "wt");
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      fprintf(dev_null, "%d\t", c[i][j]);
    }
    fprintf(dev_null, "\n");
  }
  fclose(dev_null);
  return 0;
}
