.PHONY: all child parent generator

all: child parent generator

child: bin src/child.c
	gcc -o bin/child.out src/child.c

parent: bin src/parent.c
	gcc -o bin/parent.out src/parent.c

generator: bin src/generator.c
	gcc -o bin/generator.out src/generator.c
bin:
	mkdir bin
