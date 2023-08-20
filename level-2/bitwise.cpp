// Standard libraries
#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "default_library.h"
#include "bitwise.h"
#pragma warning(disable:4996)

void printNumAndHex(u_int num) {
	printf("Decimal: %d\n", num);
	printf("Binary: ");
	for (int i = sizeof(num) * 8 - 1; i >= 0; i--)
		printf("%d", num >> i & 1);
	putchar('\n');
}

u_short swap_bytes(u_short i) {
	return (i << 8) + (i >> 8);
}

void swap_bytes() {
	printf("Enter a hexadecimal number (up to four digits): ");
	u_short user_input;
	// Have to use this as per book's instructions
	if (scanf("%hx", &user_input) != 1) return;
	printf("Number with bytes swapped: %hx\n", swap_bytes(user_input));
}

int count_ones(u_char ch) {
	// Part b wanted without loops
	return ch ? 1 + count_ones(ch & (ch-1)) : 0;
}

int lowestBitNumber(int num) {
	return num & -num;
}

u_int toggleBit(u_int num, int bit) {
	int rightBits = sizeof(int) * 8 - bit;
	return (((num >> bit) ^ 1) << bit) + (num << rightBits >> rightBits);
}

int lastBitOff(int num) {
	// Alternate:
	// return num - (num & -num);
	return num & (num - 1);
}

int bitAdd(int num1, int num2) {
	int carry, result;
	do {
		carry = (num1 & num2) << 1;
		result = num1 ^ num2;
		num1 = carry;
		num2 = result;
	} while (carry);
	return result;
}

int bitSub(int num1, int num2) {
	return bitAdd(num1, (~num2) + 1);
}

int bitMul(int num1, int num2) {
	int result = 0;
	while (num2) {
		if (num2 & 1) result = bitAdd(result, num1);
		num2 >>= 1;
		num1 <<= 1;
	}
	return result;
}

int bitDiv(int num1, int num2) {
	int result = 0;
	int divisor, subres;
	while (num1 >= num2) {
		divisor = num2;
		subres = 1;
		while (divisor <= num1) {
			divisor <<= 1;
			subres <<= 1;
		}
		result ^= subres >> 1;
		num1 = bitSub(num1, divisor >> 1);
	}
	return result;
}

int bitMod(int num1, int num2) {
	int result = 0;
	int divisor, subres;
	while (num1 >= num2) {
		divisor = num2;
		subres = 1;
		while (divisor <= num1) {
			divisor = divisor << 1;
			subres = subres << 1;
		}
		result ^= subres >> 1;
		num1 = bitSub(num1, divisor >> 1);
	}
	return num1;
}
