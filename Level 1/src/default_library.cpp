// Standard libraries
#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include "default_library.h"

// Custom safe input readers
double getnum(int);

/* Purpose of `cutNext`:
* -1 - Don't cut
* 0 - Default
* 1 - Cut
*/
double getnum(int cutNext) {
	char c;
	double read = 0;
	while ((c = getchar()) >= '0' && c <= '9'){
		read *= 10;
		read += c - '0';
	}
	if (c == '.') {
		double frac = 1;
		while ((c = getchar()) >= '0' && c <= '9') {
			frac /= 10;
			read += (c - '0') * frac;
		}
	}
	if (cutNext == 1 || cutNext == 0 && (c == ' ' || c == '\n')) {
		return read;
	}
	ungetc(c, stdin);
	return read;
}
