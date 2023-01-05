test: test.o game.o
	gcc test.o game.o -o test
test.o:test.c
	gcc -c test.c -o test.o
game.o:game.c
	gcc -c game.c -o game.o
.PHONY:clean
clean:
	rm *.o test

