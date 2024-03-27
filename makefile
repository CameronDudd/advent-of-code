GCC = gcc
GCCDEBUG = -g
GCCFLAGS = $(GCCDEBUG) -Wall -std=c99
SRC = ./src/*.c
INCLUDE = -I./include/
GCCPREFIX = $(GCC) $(GCCFLAGS) $(SRC) $(INCLUDE)
OUT = ./bin

collections:
	$(GCCPREFIX) -o $(OUT)/collections

fileio:
	$(GCCPREFIX) -o $(OUT)/fileio

main:
	$(GCCPREFIX) ./aoc/2015/day/1/main.c -o $(OUT)/main
