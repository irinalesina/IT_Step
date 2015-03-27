all: main.o funs.o
	gcc -o bin/app obj/main.o obj/work_with_number.o

funs.o: work_with_number.c folders
	gcc --std=c11 -o obj/work_with_number.o -c work_with_number.c

main.o: main.c folders
	gcc --std=c11 -o obj/main.o -c main.c

clean:
	rm -rf bin obj 

folders:
	mkdir bin
	mkdir obj
