// Copyright 2024 Cameron Dudd

#include <collections.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void readlines(char *filename, List *buff) {
  // create file descriptor
  int fd = open(filename, O_RDONLY);
  if (fd == -1) {
    fprintf(stderr, "Failed to open file");
    return;
  }

  // read the file
  int  bytesRead = 0;
  char ch        = EOF;
  do {
    while ((bytesRead = read(fd, &ch, 1)) > 0) {
      appendList(buff, ch);
    }
  } while (ch != EOF && bytesRead != 0);

  // close the file
  close(fd);
}

int testFileIO() {
  char filename[] =
      "/home/cameron/coding/personal/C/adventofcode/2023/day/1/input";
  List linesBuff;

  initList(&linesBuff, 1);
  readlines(filename, &linesBuff);
  printList(&linesBuff);
  freeList(&linesBuff);
  return 1;
}

// int main() { return testFileIO(); }
