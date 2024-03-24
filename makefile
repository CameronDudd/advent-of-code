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

aoc:  # just day 1 for now; TODO: configure days
	$(GCCPREFIX) ./2023/day/1/main.c -o $(OUT)/2023-day-1
