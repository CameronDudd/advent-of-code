// Copyright 2024 Cameron Dudd

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void part1(char *filename) {
  int fd = open(filename, O_RDONLY);
  char ch;
  int c = 0;
  int bytesRead = 0;
  do {
    bytesRead = read(fd, &ch, 1);
    if (ch == '(') {
      c++;
    }
    if (ch == ')') {
      c--;
    }
  } while (bytesRead != 0);
  close(fd);
  fprintf(stdout, "%i\n", c);
}

void part2(char *filename) {
  int fd = open(filename, O_RDONLY);
  char ch;
  int c = 0;
  int bytesRead = 0;
  int totalBytesRead = 0;
  do {
    bytesRead = read(fd, &ch, 1);
    totalBytesRead += bytesRead;
    if (ch == '(') {
      c++;
    }
    if (ch == ')') {
      c--;
    }
    if (c == -1) {
      break;
    }
  } while (bytesRead != 0);
  close(fd);
  fprintf(stdout, "%i\n", c);
  fprintf(stdout, "%i\n", totalBytesRead);
}

int main() {
  char filename[] =
      "/home/cameron/coding/personal/c/advent-of-code/aoc/2015/day/1/input";
  part1(filename);
  part2(filename);
  return 1;
}
