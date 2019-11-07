#ifndef _MATRIX_H
#define _MATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
  int nRows;
  int nCols;
  int *elements;
} Matrix;

struct Matrix *matrix_init(int nRows, int nCols, int initialValue);
void matrix_free(struct Matrix *matrix);
int matrix_display(struct Matrix *matrix);

#endif
