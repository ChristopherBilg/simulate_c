#include "matrix.h"

int main(int argc, char **argv) {
  printf("Test\n");
  return EXIT_SUCCESS;
}

struct Matrix *matrix_init(int nRows, int nCols, int initialValue) {
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

int matrix_display(struct Matrix *matrix) {}
