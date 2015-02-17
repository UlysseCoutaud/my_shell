CC=gcc
CFLAGS=-Wall -Werror -lpthread
SOURCES=$(wildcard *.c)
OBJ=$(patsubst %.c, %.o, $(SOURCES))
EXE=eval myshell

myshell: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

eval.o: myshell.h
myshell.o: myshell.h csapp.h
parseline.o: myshell.h csapp.h
csapp.o: csapp.h
util.o: util.h

clean:
	rm -f *.o $(EXE)
