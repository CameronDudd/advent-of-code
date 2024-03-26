// Copyright 2024 Cameron Dudd

#include <collections.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initList(List *l, int initSize) {
  l->list = (char *)malloc(initSize * sizeof(char));
  l->used = 0;
  l->size = initSize;
}

void freeList(List *l) {
  free(l->list);
  l->list = NULL;
  l->used = l->size = 0;
}

void appendList(List *l, char element) {
  if (l->used == l->size) {
    l->size *= 2;
    l->list = realloc(l->list, l->size * sizeof(char));
  }
  l->list[l->used++] = element;
}

void arrcpy(char *src, List *dst) {
  char *src_ptr = (char *)src;
  while (*src_ptr != '\0') {
    appendList(dst, *src_ptr);
    src_ptr++;
  }
}

void listcpy(List *src, List *dst) {
  char *src_ptr = (char *)src->list;
  char *dst_ptr = (char *)dst->list;

  while (*src_ptr != '\0') {
    *dst_ptr = *src_ptr;
    dst_ptr++;
    src_ptr++;
  }
}

void printList(List *l) {
  char *lptr = l->list;
  while (*lptr != '\0') {
    fprintf(stdout, "%c", *lptr++);
  }
  fprintf(stdout, "\n");
}

int cmpstr(char *str, const char *sub) {
  if (!str || !sub) {
    return -1;
  }
  if (strlen(str) < strlen(sub)) {
    return -1;
  }
  while (*str && *sub) {
    if (*str != *sub) {
      return -1;
    }
    sub++, str++;
  }
  return 1;
}

char *tokenizeStr(char *str, const char *delim) {  // destructive
  // FIXME (cameron): currently overflows
  static int i = 0;
  if (*str == *delim) {
    i++;
  }
  char *token = str + i;
  while (cmpstr(str + i, delim) != 1 && *(str + i) != '\0') {
    i++;
  }
  str[i] = '\0';
  return token;
}

int testCollections() {
  List test1;
  List *test1_ptr = &test1;
  initList(test1_ptr, 1);
  appendList(test1_ptr, 'a');
  appendList(test1_ptr, 'b');
  appendList(test1_ptr, 'c');

  List test2;
  List *test2_ptr = &test2;
  initList(test2_ptr, 2);

  listcpy(test1_ptr, test2_ptr);

  fprintf(stdout, "test1: ");
  printList(test1_ptr);
  fprintf(stdout, "test2: ");
  printList(test2_ptr);

  freeList(test1_ptr);
  freeList(test2_ptr);

  return 1;
}

// int main() { return testCollections(); }
