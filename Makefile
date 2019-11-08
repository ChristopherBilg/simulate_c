generated_files=output.out

all: ${generated_files}

output.out: main.c matrix/matrix.c
	gcc -std=c99 -g -O3 -Wall -Wextra -o output.out main.c matrix/matrix.c

clean:
	rm -f ${generated_files}
