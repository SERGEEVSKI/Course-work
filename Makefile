.PHONY: all clean tournament-grid

all: bin/tournament-grid
	
bin/tournament-grid : build/src/main.o build/src/graphics.o build/src/functions.o
	gcc build/src/main.o build/src/graphics.o build/src/functions.o -o bin/tournament-grid

build/src/functions.o : src/functions.c
	gcc -Wall -Werror -c src/functions.c -o build/src/functions.o

build/src/graphics.o : src/graphics.c
	gcc -Wall -Werror -c src/graphics.c -o build/src/graphics.o

build/src/main.o : src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o

clean:
	rm -rf build/src/*.o build/test/*.o bin/tournament-grid 
