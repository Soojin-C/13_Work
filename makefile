all: work13.o
	gcc work13.o

work13.o: work13.c
	gcc -c work13.c

run:
	./a.out

clean:
	rm text.txt
	rm a.out
