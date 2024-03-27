// 2*l*w + 2*w*h + 2*h*l
// 2(lw + wh + hl)
// format - l x w x h

#include <collections.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

struct line {
  int length;
  int width;
  int height;
};

void part1(char *filename) {
  int fd = open(filename, O_RDONLY);
  int bytes_read = -1;
  char ch;

  // 1. read lines into a buffer
  // 2. process the buffer, split on delim 'x'
  // 3. add 2(lw + wh + hl) to total
  // 4. return total
  char l[4];
  char w[4];
  char h[4];
  int seen_delim = 0;
  while (bytes_read != 0) {
    bytes_read = read(fd, &ch, 1);
    if (ch == 'x') {
      seen_delim++;
    }
    switch (seen_delim % 3) {
      case 0:
        return;
      case 1:
        return;
      case 2:
        return;
    }
    fprintf(stdout, "%s", tmp);
  }
  close(fd);
}

void part2(char *filename) {}

int main() {
  char filename[] =
      "/home/cameron/coding/personal/c/advent-of-code/aoc/2015/day/2/"
      "test_input";
  part1(filename);
  part2(filename);
  return 1;
}
