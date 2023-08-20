// Standard libraries
#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include "default_library.h"
#include "pointers.h"

void reverse1() {
	printf("Enter a message: ");
	char input[100] = { 0 };
	char size = 0;
	for (int i = 0; i < 100; i++) {
		char currChar = getchar();
		if (currChar == '\n') break;
		input[size] = currChar;
		size++;
	}
	for (int i = size; i >= 0; i--) {
		putchar(input[i]);
	}
}

void reverse2() {
	printf("Enter a message: ");
	char input[100] = { 0 };
	int* p = (int*)input;
	char size = 0;
	for (int i = 0; i < 100; i++) {
		char currChar = getchar();
		if (currChar == '\n') break;
		*(p + size) = currChar;
		size++;
	}
	for (int i = size; i >= 0; i--) {
		putchar(*(p + i));
	}
}

void pointerPalindrome() {
	printf("Enter a message: ");
	char input[100] = { 0 };
	char* p = (char*)input;
	char size = 0;
	for (int i = 0; i < 100; i++) {
		char currChar = tolower(getchar());
		if (currChar == '\n') break;
		*(p + size) = currChar;
		size++;
	}
	bool palindrome = true;
	char* r = p + size;
	while (p < r) {
		while (!isalpha(*p)) p++;
		while (!isalpha(*r)) r--;
		if (*p != *r) {
			palindrome = false;
			break;
		}
		p++;
		r--;
	}
	if (palindrome) printf("Palindrome");
	else printf("Not a palindrome");
}

void palindromeRec(char* p, char* r){
	if (p >= r) printf("Palindrome");
	else if (!isalpha(*p)) palindromeRec(++p, r);
	else if (!isalpha(*r)) palindromeRec(p, --r);
	else if (*p != *r) printf("Not palindrome");
	else palindromeRec(++p, --r);
}

void isPalindrome(char* input) {
	char* r = input;
	while (*r != '\0') r++;
	palindromeRec(input, r);
}

void recursivePointerPalindrome() {
	printf("Enter a message: ");
	char input[100] = { 0 };
	char* p = (char*)input;
	char size = 0;
	for (int i = 0; i < 100; i++) {
		char currChar = tolower(getchar());
		if (currChar == '\n') break;
		*(p + size) = currChar;
		size++;
	}
	isPalindrome(p);
}

void showList(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("list + %d: ", i);
		for (long long j = sizeof(arr); j > 0; j--) {
			printf("%.2X ", (unsigned char)((long long)arr / (long long)pow(256, j - 1) % 256));
		}
		printf("contains %d\n", *(arr++));
	}
}

void reverseList(int* arr, int size) {
	arr += size-1;
	for (int i = 0; i < size; i++) printf("%d ", *(arr--));
}

void showChars(const char* s) {
	for (int n = 0; *(s + n) != '\0'; n++) {
		printf("char %d: \"%c\" (%i)\n", n + 1, *(s + n), *(s + n));
	}
}

void show2D(int* arr, int r, int c){
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("\t%d", *(arr + i * c + j));
		}
		putchar('\n');
	}
}

void multiplyArr() {
	const int m = 3, n = 5, o = 2;
	int m1[m][n] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
	int m2[n][o] = { {1,2},{3,4},{5,6},{7,8},{9,10} };
	int m3[m][o] = { 0 };
	int* pm1 = (int*) m1;
	int* pm2 = (int*) m2;
	int* pm3 = (int*) m3;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < o; j++) {
			for (int k = 0; k < n; k++) {
				*(pm3 + i * o + j) += *(pm1 + i * n + k) * *(pm2 + k * o + j);
			}
		}
	}
	show2D(pm3, m, o);
}

void populateArr(){
	const int r = 5;
	const int c = 4;
	int x[r][c];
	int *p1[r];
	int (*p2)[c];
	int cnt = 1;
	for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++){
		for (int j = 0; j < sizeof(x[0]) / sizeof(x[0][0]); j++){
			x[i][j] = cnt++;
		}
	}

	for (int i = 0; i < sizeof(p1) / sizeof(p1[0]); i++){
		p1[i] = &x[i][0];
	}

	for (int i = 0; i < sizeof(p1) / sizeof(p1[0]); i++){
		for (int j = 0; j < (int) (p1[1] - p1[0]); j++){
			printf("%3d", *(p1[i] + j));
		}
		putchar('\n');
	}

	p2 = &x[0];

	for (int row = 0; row < 5; row++){
		for (int col = 0; col < 4; col++){
			// Step by rows until at right row
			// Convert to int*, pointing to an int
			// Step by columns until at right column
			// Dereference pointer
			// Read element
			printf("%3d", *((int*)(p2+row)+col));
		}
		putchar('\n');
	}
}
