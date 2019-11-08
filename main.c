#include "main.h"

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
