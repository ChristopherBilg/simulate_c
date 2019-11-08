generated_files=output.out

all: output.out

output.out: main.c matrix/matrix.c
	gcc -std=c99 -g -O3 -Wall -o output.out main.c matrix/matrix.c

clean:
	rm -f ${generated_files}
