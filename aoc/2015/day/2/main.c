// 2*l*w + 2*w*h + 2*h*l
// 2(lw + wh + hl)
// format - l x w x h

#include <collections.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void part1(char *filename) {
  int fd = open(filename, O_RDONLY);
  int bytes_read = -1;
  char ch;

  // 1. read lines into a buffer
  // 2. process the buffer, split on delim 'x'
  // 3. add 2(lw + wh + hl) to total
  // 4. return total

  int il;
  int iw;
  int ih;
  int len = 5;
  char l[] = {'\0' * len};
  char w[] = {'\0' * len};
  char h[] = {'\0' * len};
  int cur_char = 0;
  int seen_delim = 0;
  int total = 0;

  while (bytes_read != 0) {
    bytes_read = read(fd, &ch, 1);

    // check current char for x or newline
    if (ch == 'x' || ch == '\n') {
      cur_char = 0;
      seen_delim++;
      continue;
    }

    // write to correct buff
    switch (seen_delim % 4) {
      case 0:
        l[cur_char] = ch;
        cur_char++;
        break;
      case 1:
        w[cur_char] = ch;
        cur_char++;
        break;
      case 2:
        h[cur_char] = ch;
        cur_char++;
        break;
      case 3:
        il = str2int(l);
        iw = str2int(w);
        ih = str2int(h);
        // total = total + (2 * ((il * iw) + (iw * ih) + (ih * il)));
        break;
    }
  }
  fprintf(stdout, "%i", total);
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
