generated_files=main.out

all: main.out

main.out: main.c matrix.c
	gcc -std=c99 -g -O3 -Wall -o main.out main.c matrix.c

clean:
	rm -f ${generated_files}
