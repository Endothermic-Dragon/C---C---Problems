// Standard libraries
#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "default_library.h"
#include "segment_display.h"

void displaySegment() {
	printf("What number would you like to display? ");
	int num = (int)getnum(0);
	int digits[10] = { 0 };
	int numDigits = 0;
	splitNum(num, digits, numDigits);
	for (int i = 0; i < numDigits; i++) {
		if (segments[digits[i]][0]) printf(" _ ");
		else printf("   ");
	}
	for (int j = 0; j < 2; j++) {
		putchar('\n');
		for (int i = 0; i < numDigits; i++) {
			if (segments[digits[i]][3 * j + 1]) printf("|");
			else printf(" ");
			if (segments[digits[i]][3 * j + 2]) printf("_");
			else printf(" ");
			if (segments[digits[i]][3 * j + 3]) printf("|");
			else printf(" ");
		}
	}
}

void splitNum(int num, int* digits, int& numDigits) {
	int numCopy = num;
	numDigits = 0;
	if (num == 0) numDigits = 1;
	while (numCopy != 0) {
		numDigits++;
		numCopy /= 10;
	}
	int k = (int) pow(10, numDigits - 1);
	for (int i = 0; i < numDigits; i++) {
		*(digits + i) = num % (k * 10) / k;
		k /= 10;
	}
}
