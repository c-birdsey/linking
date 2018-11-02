CFLAGS = -Wall -pedantic -ldl -g

self-linker: self-linker.c
	gcc $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f self-linker
