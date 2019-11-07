generated_files=main.out

all: main.out

main.out: matrix.c
	gcc -std=c99 -g -O3 -Wall -o main.out matrix.c

clean:
	rm -f ${generated_files}
