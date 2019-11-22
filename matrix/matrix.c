#include "matrix.h"

int main(int argc, char **argv) {
  if (argc > 1) {
    printf("Correct Usage: %s", argv[0]);
    return EXIT_SUCCESS;
  }

  struct Matrix *m1 = matrix_init(1, 3, 2);
  struct Matrix *m2 = matrix_init(3, 1, 3);
  struct Matrix *m3 = matrix_init(1, 1, 0);

  matrix_multiply(m3, m1, m2);
  matrix_display(m3);

  matrix_free(m1);
  matrix_free(m2);
  matrix_free(m3);
  return EXIT_SUCCESS;
}

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

  int size = nRows * nCols;
  for (int i = 0; i < size; i++)
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

  int size = matrix->nRows * matrix->nCols;
  for (int i = 0; i < size; i++) {
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

  int size = matrix->nRows * matrix->nCols;
  for (int i = 0; i < size; i++)
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

  int size = dest->nRows * dest->nCols;
  for (int i = 0; i < size; i++)
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

  int size = dest->nRows * dest->nCols;
  for (int i = 0; i < size; i++)
    dest->elements[i] = a->elements[i] - b->elements[i];

  return 0;
}

int matrix_insert(struct Matrix *matrix, int row, int col, int value) {
  if (matrix == NULL || matrix->elements == NULL)
    return 1;

  if (row < 0 || row > (matrix->nRows - 1))
    return 1;

  if (col < 0 || col > (matrix->nCols - 1))
    return 1;

  int index = (row * matrix->nCols) + col;
  matrix->elements[index] = value;

  return 0;
}

int matrix_transpose(struct Matrix *matrix) {
  if (matrix == NULL || matrix->elements == NULL)
    return 1;

  struct Matrix *temp = matrix_init(matrix->nCols, matrix->nRows, 0);
  for (int i = 0; i < matrix->nRows; i++)
    for (int j = 0; j < matrix->nCols; j++)
      temp->elements[(j * matrix->nRows) + i] =
          matrix->elements[(i * matrix->nCols) + j];

  int size = temp->nRows * temp->nCols;
  for (int i = 0; i < size; i++)
    matrix->elements[i] = temp->elements[i];

  matrix->nRows = temp->nRows;
  matrix->nCols = temp->nCols;

  return 0;
}

int matrix_scale(struct Matrix *matrix, int scale) {
  if (matrix == NULL || matrix->elements == NULL)
    return 1;

  int size = matrix->nRows * matrix->nCols;
  for (int i = 0; i < size; i++)
    matrix->elements[i] *= scale;

  return 0;
}

int matrix_multiply(struct Matrix *dest, struct Matrix *a, struct Matrix *b) {
  if (dest == NULL || a == NULL || b == NULL)
    return 1;

  if (dest->elements == NULL || a->elements == NULL || b->elements == NULL)
    return 1;

  if (a->nCols != b->nRows)
    return 1;

  if (dest->nRows != a->nRows || dest->nCols != b->nCols)
    return 1;

  // Multiplication algorithm
  int sum;
  for (int i = 0; i < dest->nRows; i++)
    for (int j = 0; j < dest->nCols; j++) {
      sum = 0;
      for (int k = 0; k < a->nCols; k++)
        sum += a->elements[(i * dest->nRows) + k] *
               b->elements[(k * dest->nCols) + j];
      dest->elements[(i * dest->nCols) + j] = sum;
    }

  return 0;
}
