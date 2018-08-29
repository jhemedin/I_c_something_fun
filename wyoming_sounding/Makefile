SHELL=/bin/sh
CC=gcc
CFLAGS=-g 
OBJS = main.o sounding_io.o conversion.o
LIBS = -lm

.c.o : 
	${CC} ${CFLAGS} -c $< -o $@

all: main.o conversion.o sounding_io.o 
	${CC} ${CFLAGS} -o sounding ${OBJS} ${LIBS}

conversion.o: conversion.c
	${CC} ${CFLAGS} -c $< -o $@

main.o: main.c
	${CC} ${CFLAGS} -c $< -o $@

sounding_io.o: sounding_io.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	rm *.o 
