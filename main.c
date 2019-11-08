#include "main.h"

int main(int argc, char **argv) {
  struct Matrix *m1 = matrix_init(5, 3, 1);
  struct Matrix *m2 = matrix_init(5, 3, 1);
  struct Matrix *m3 = matrix_init(5, 3, 9);

  matrix_add(m3, m1, m2);
  matrix_display(m3);

  matrix_subtract(m3, m1, m2);
  matrix_display(m3);

  matrix_free(m1);
  matrix_free(m2);
  matrix_free(m3);
  return EXIT_SUCCESS;
}
