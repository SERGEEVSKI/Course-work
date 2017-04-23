.PHONY: all clean test-graphics

all: bin/test-graphics
	
bin/test-graphics : build/src/main.o build/src/graphics.o
	gcc build/src/main.o build/src/graphics.o -o bin/test-graphics

build/src/graphics.o : src/graphics.c
	gcc -Wall -Werror -c src/graphics.c -o build/src/graphics.o

build/src/main.o : src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

clean:
	rm -rf build/src/*.o build/test/*.o bin/* 
