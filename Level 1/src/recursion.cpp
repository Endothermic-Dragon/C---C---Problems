// Standard libraries
#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include "default_library.h"
#include "recursion.h"

int recursion_baseExp(int base, int exp) {
	if (exp == 1) return base;
	return base * recursion_baseExp(base, exp - 1);
}

void recursion_prnt20(int n) {
	printf("%d\n", n);
	if (n > 1) recursion_prnt20(n - 1);
}

void recursion_prnt02(int n) {
	if (n > 1) recursion_prnt02(n - 1);
	printf("%d\n", n);
}

int recursion_countDigits(int n) {
	if (n == 0) return 0;
	return recursion_countDigits(n / 10) + 1;
}

int recursion_gcd(int a, int b) {
	if (a % b == 0) return b;
	return recursion_gcd(b, a % b);
}

int recursion_sum(int n) {
	if (n == 1) return 1;
	return n + recursion_sum(n - 1);
}

// The function below basically performs an exponentiation
// Expands definition to fit with negative integer exponents
double recursion_baseExpAdv(double base, int exp) {
	if (exp == 0) return 1;
	else if (exp > 0) return base * recursion_baseExp(base, exp - 1);
	else return 1.0 / (base * recursion_baseExp(base, -exp - 1));
}

void recursion_drawTriangle(int h) {
	if (h == 0) return;
	recursion_drawTriangle(h - 1);
	for (int i = 0; i < h; i++) {
		putchar('#');
	}
	putchar('\n');
}

void recursion_drawTriangleUpsideDown(int h) {
	if (h == 0) return;
	for (int i = 0; i < h; i++) {
		putchar('#');
	}
	putchar('\n');
	recursion_drawTriangleUpsideDown(h - 1);
}
