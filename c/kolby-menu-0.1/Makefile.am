# Define required macros here
SHELL = /bin/sh
PROGRAM = menu

FILES =  main.c menu.h menu.c
CFLAGS = -Wall
CC = gcc
INCLUDE =

menu:${OBJ}
	${CC} ${CFLAGS} ${INCLUDES} -o ${PROGRAM} ${FILES}

clean:
	rm -f *.o
