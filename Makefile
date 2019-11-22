generated_files=matrix.out
key_args=-Wall -Wextra -std=c99 -g -O3

all: ${generated_files}

matrix.out: matrix/matrix.c
	gcc ${key_args} -o matrix.out matrix/matrix.c

clean:
	rm -f ${generated_files}
