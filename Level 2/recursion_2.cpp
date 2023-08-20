// Standard libraries
#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "default_library.h"
#include "recursion_2.h"

int findmin(int* list, int n) {
	if (n == 1) return *list;
	return min(*list, findmin(list + 1, n - 1));
}

int findsum(int* list, int n) {
	if (n == 0) return 0;
	return *list + findsum(list + 1, n - 1);
}

bool ispalindrome(cc* p, cc* r) {
	if (p >= r) return true;
	else if (*p != *r) return false;
	else return ispalindrome(++p, --r);
}

bool ispalindrome(cc* input) {
	return ispalindrome(input, input + strlen(input) - 1);
}

void printHex(u_int num, char bytesLeft) {
	if (bytesLeft == 0) return;
	int partNum = num << ((sizeof(u_int) - bytesLeft) * 8) >> ((sizeof(u_int) - 1) * 8);
	printf("%.2X ", partNum);
	printHex(num, bytesLeft - 1);
}

void printBin(u_int num, char bitsLeft) {
	if (bitsLeft == 0) return;
	printf("%d", num >> (bitsLeft - 1) & 1);
	if (bitsLeft % 4 - 1 == 0) putchar(' ');
	printBin(num, bitsLeft - 1);
}

void intToHexAndBin(u_int input) {
	char numBytes = sizeof(u_int);
	printHex(input, numBytes);
	putchar('\n');
	printBin(input, numBytes * 8);
	putchar('\n');
}

void flipChars(char* s, char* e) {
	if (s >= e) return;
	char t = *s;
	*s = *e;
	*e = t;
	flipChars(s + 1, e - 1);
}

void reverse(char* srcStr) {
	flipChars(srcStr, srcStr + strlen(srcStr) - 1);
}

ll fibonacci(int val) {
	static ll memoize[100] = { 0 };
	if (val == 0) return 1;
	if (val == 1) return 0;
	ll res = memoize[val-2] == 0 ? fibonacci(val - 1) + fibonacci(val - 2) : memoize[val-2];
	memoize[val - 2] = res;
	return res;
}

bool balance(cc*& str) {
	while (*str != '(' && *str != '{' && *str != ')' && *str != '}' && *str) str++;

	if (*str == '(' || *str == '{') {
		char close = *str == '(' ? ')' : '}';
		str++;
		if (balance(str) && close == *str) {
			str++;
			return balance(str);
		}
		return false;
	}
	return true;
}

bool checkNesting(cc* str) {
	return balance(str) && !*str;
}
