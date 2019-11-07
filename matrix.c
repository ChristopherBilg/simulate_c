#include "matrix.h"

struct Matrix *matrix_init(int nRows, int nCols, int initialValue) {
  if (nRows < 1 || nCols < 1)
    return NULL;
  
  struct Matrix *matrix = (struct Matrix *)malloc(sizeof(struct Matrix));
  if (matrix == NULL)
    return NULL;

  matrix->elements = (int *)malloc(sizeof(int) * nRows * nCols);
  if (matrix->elements == NULL) {
    free(matrix);
    return NULL;
  }

  matrix->nRows = nRows;
  matrix->nCols = nCols;

  for (int i = 0; i < (nRows * nCols); i++)
    matrix->elements[i] = initialValue;

  return matrix;
}

void matrix_free(struct Matrix *matrix) {
  free(matrix->elements);
  free(matrix);
}

int matrix_display(struct Matrix *matrix) {
  if (matrix == NULL || matrix->elements == NULL)
    return 1;

  for (int i = 0; i < (matrix->nRows * matrix->nCols); i++) {
    printf("%d", matrix->elements[i]);
    if ((i + 1) % matrix->nCols == 0)
      printf("\n");
    else
      printf(" ");
  }
  
  return 0;
}

