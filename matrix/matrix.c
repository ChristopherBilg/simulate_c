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

int matrix_populate(struct Matrix *matrix, int modulo) {
  if (matrix == NULL || matrix->elements == NULL)
    return 1;

  if (modulo < 0)
    modulo = -modulo;

  for (int i = 0; i < (matrix->nRows * matrix->nCols); i++)
    matrix->elements[i] = rand() % modulo;

  return 0;
}

int matrix_add(struct Matrix *dest, struct Matrix *a, struct Matrix *b) {
  if (dest == NULL || a == NULL || b == NULL)
    return 1;

  if (dest->elements == NULL || a->elements == NULL || b->elements == NULL)
    return 1;

  if (dest->nRows != a->nRows || a->nRows != b->nRows)
    return 1;

  if (dest->nCols != a->nCols || a->nCols != b->nCols)
    return 1;

  for (int i = 0; i <(dest->nRows * dest->nCols); i++)
    dest->elements[i] = a->elements[i] + b->elements[i];

  return 0;
}

int matrix_subtract(struct Matrix *dest, struct Matrix *a, struct Matrix *b) {
  if (dest == NULL || a == NULL || b == NULL)
    return 1;

  if (dest->elements == NULL || a->elements == NULL || b->elements == NULL)
    return 1;

  if (dest->nRows != a->nRows || a->nRows != b->nRows)
    return 1;

  if (dest->nCols != a->nCols || a->nCols != b->nCols)
    return 1;

  for (int i = 0; i <(dest->nRows * dest->nCols); i++)
    dest->elements[i] = a->elements[i] - b->elements[i];

  return 0;
}
