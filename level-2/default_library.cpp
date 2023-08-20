// Standard libraries
#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "default_library.h"

/* Purpose of `cutNext`:
* -1 - Don't cut
* 0 - Default
* 1 - Cut
*/

double getnum(int cutNext) {
    return getnum(cutNext, stdin);
}

double getnum(int cutNext, FILE* fp) {
    char c;
    double read = 0;
    bool i = false, neg = false;

    if ((c = (char) fgetc(fp)) == '-') neg = true;
    else ungetc(c, fp);

    while ((c = (char) fgetc(fp)) >= '0' && c <= '9') {
        i = true;
        read *= 10;
        read += (double) c - '0';
    }
    if (c == '.') {
        double frac = 1;
        while ((c = (char) fgetc(fp)) >= '0' && c <= '9') {
            i = true;
            frac /= 10;
            read += ((double)c - '0') * frac;
        }
    }
    else if (i == false) c = (char) fgetc(fp);
    if (cutNext == 1 || cutNext == 0 && (c == ' ' || c == '\n')) {
        return i ? (neg ? -read : read) : -1;
    }
    ungetc(c, fp);
    return i ? (neg ? -read : read) : -1;
}

double getnum(cc* str) {
    return getnum((char*)str);
}

double getnum(char* str) {
    char c;
    double read = 0;
    bool i = false, neg = false;

    if (*str == '-') {
        neg = true;
        str++;
    }

    while ((c = *str) >= '0' && c <= '9') {
        i = true;
        str++;
        read *= 10;
        read += (double)c - '0';
    }
    if (c == '.') {
        double frac = 1;
        while ((c = *str) >= '0' && c <= '9') {
            i = true;
            str++;
            frac /= 10;
            read += ((double)c - '0') * frac;
        }
    }
    return i ? (neg ? -read : read) : -1;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a > b ? b : a;
}
