// Copyright 2024 Cameron Dudd

#ifndef COLLECTIONS_H
#define COLLECTIONS_H

typedef struct {
  char *list;
  int used;
  int size;
} List;

extern void initList(List *l, int initSize);
extern void appendList(List *l, char element);
extern void listcpy(List *src, List *dst);
extern void printList(List *l);
extern void freeList(List *l);
extern int cmpstr(char *str, const char *sub);
extern char *tokenizeStr(char *str, const char *delim);
extern int char2int(char *str);
extern int str2int(char *str);
extern int testCollections();

#endif /* COLLECTIONS_H */
