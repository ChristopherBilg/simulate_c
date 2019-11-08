generated_files=output

all: output

output: main.c matrix/matrix.c
	gcc -std=c99 -g -O3 -Wall -o output main.c matrix/matrix.c

clean:
	rm -f ${generated_files}
