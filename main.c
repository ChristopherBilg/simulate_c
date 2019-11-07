#include "main.h"

int main(int argc, char **argv) {
  struct Matrix *m1 = matrix_init(5, 3, 1);
  matrix_populate(m1, 10);
  matrix_display(m1);

  matrix_free(m1);
  return EXIT_SUCCESS;
}
