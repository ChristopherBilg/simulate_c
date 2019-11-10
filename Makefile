generated_files=output.out
key_args=-Wall -Wextra -std=c99 -g -O3 -fsanitize=address,leak,undefined

all: ${generated_files}

output.out: main.c matrix/matrix.c
	gcc ${key_args} -o output.out main.c matrix/matrix.c

clean:
	rm -f ${generated_files}
