// Copyright 2024 Cameron Dudd

// 2*l*w + 2*w*h + 2*h*l
// 2(lw + wh + hl)
// format - l x w x h

#include <collections.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>

void reset_buff(char *buff) {
  for (int i = 0; i < 10; i++) {
    buff[i] = '\0';
  }
}

void part1(char *filename) {
  int fd = open(filename, O_RDONLY);
  int bytes_read = -1;
  char ch;
  int il;
  int iw;
  int ih;
  int slack = 0;
  char l[10] = {'\0' * 10};
  char w[10] = {'\0' * 10};
  char h[10] = {'\0' * 10};
  int cur_char = 0;
  int seen_delim = 0;
  int total = 0;

  while (bytes_read != 0) {
    bytes_read = read(fd, &ch, 1);

    // check current char for x or newline
    if (ch == 'x') {
      cur_char = 0;
      seen_delim++;
    } else if (ch == '\n') {
      // calculate total
      il = str2int(l);
      iw = str2int(w);
      ih = str2int(h);

      int lw = il * iw;
      int lh = il * ih;
      int wh = iw * ih;
      slack = min(lw, min(lh, wh));  // find smallest side for slack

      // DEBUG: fprintf(stdout, "%i x %i x %i\n", il, iw, ih);
      total += 2 * (lw + lh + wh) + slack;

      // reset
      cur_char = 0;
      seen_delim = 0;
      reset_buff(l);
      reset_buff(w);
      reset_buff(h);
    } else {
      // write to correct buff
      switch (seen_delim) {
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
      }
    }
  }
  fprintf(stdout, "%i\n", total);
  close(fd);
}

void part2(char *filename) {
  int fd = open(filename, O_RDONLY);
  int bytes_read = -1;
  char ch;
  int il;
  int iw;
  int ih;
  char l[10] = {'\0' * 10};
  char w[10] = {'\0' * 10};
  char h[10] = {'\0' * 10};
  int cur_char = 0;
  int seen_delim = 0;
  int total = 0;

  while (bytes_read != 0) {
    bytes_read = read(fd, &ch, 1);

    // check current char for x or newline
    if (ch == 'x') {
      cur_char = 0;
      seen_delim++;
    } else if (ch == '\n') {
      // calculate total
      il = str2int(l);
      iw = str2int(w);
      ih = str2int(h);

      int min1 = min(il, iw);
      int min2 = min(iw, ih);
      int ribbonLength = 2 * (min1 + min2);
      int bowLength = il * iw * ih;

      // DEBUG: fprintf(stdout, "%i x %i x %i\n", il, iw, ih);
      fprintf(stdout, "%i x %i x %i: %i length; %i bow\n", il, iw, ih,
              ribbonLength, bowLength);
      total += ribbonLength + bowLength;

      // reset
      cur_char = 0;
      seen_delim = 0;
      reset_buff(l);
      reset_buff(w);
      reset_buff(h);
    } else {
      // write to correct buff
      switch (seen_delim) {
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
      }
    }
  }
  fprintf(stdout, "%i\n", total);
  close(fd);
}

int main() {
  char filename[] =
      "/home/cameron/coding/personal/c/advent-of-code/aoc/2015/day/2/"
      "input";
  part1(filename);
  part2(filename);
  return 1;
}
