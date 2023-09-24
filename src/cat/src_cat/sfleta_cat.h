#ifndef SRC_CAT_sfleta_CAT_H_
#define SRC_CAT_sfleta_CAT_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int b, e, n, s, t, v;
} Flag;

void sfleta_cat(int argc, char const *argv[]);
void buildOutput(const char** filePathArr, size_t filesCount);
void printNonReadableChar(char c, int *NonBlankLineCount, int *everyLineCount);

#endif  // SRC_CAT_sfleta_CAT_H_
