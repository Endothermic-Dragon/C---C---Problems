#define _CRT_SECURE_NO_WARNINGS

// Standard libraries
#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "default_library.h"

#include "segment_display.h"
#include "array_challenge.h"
#include "recursion.h"
#include "pointers.h"
#include "strings.h"
#include "remind.h"
#include "bitwise.h"
#include "recursion_2.h"
#include "subarray_sum.h"
#include "sort_search.h"
#include "file_io.h"

#define MK_COLOR(r, g, b) (long)(((int)(r)<<16) + ((int)(g)<<8) + ((int)(b)))
#define GET_RED(rgb) (u_char)(rgb>>16)
#define GET_GREEN(rgb) (u_char)(rgb<<16>>24)
#define GET_BLUE(rgb) (u_char)(rgb<<24>>24)

int validateInput(int*, int);
bool validateInput(int, int*, int);
void module_2(int, char**);
void module_4(int, char**);
void module_5(int, char**);
void module_7(int, char**);
void module_8(int, char**);
void module_9(int, char**);
void module_11(int, char**);
void module_12(int, char**);

int main(int argc, char** argv)
{
	argc--;
	argv++;
	if (argc == 0) {
		printf("Note: You can run exercises via the command line too.\n");
		printf("The structure follows module -> exercise -> other inputs (if any).\n");
	}

	int validInputs[] = { 0, 1, 2, 4, 5, 7, 8, 9, 11, 12 };
	int len = sizeof(validInputs) / sizeof(validInputs[0]);

	int num = -1;
	if (argc != 0) num = (int)getnum(*argv);
	if (argc == 0 || !validateInput(num, validInputs, len)) {
		argc = 0;

		printf("Which module do you want to run? Enter a number.\n");
		printf("  0 - segment_display\n");
		printf("  1 - arrays\n");
		printf("  2 - recursion_1 (introduction)\n");
		printf("  4 - pointers\n");
		printf("  5 - strings\n");
		printf("  7 - bitwise\n");
		printf("  8 - recursion_2 (in-depth)\n");
		printf("  9 - subarray_sums\n");
		printf("  11 - sort_search\n");
		printf("  12 - file_io\n");
		printf("Note: prefix/infix/postfix completed on Google Docs\n> ");

		num = validateInput(validInputs, len);
	}
	putchar('\n');
	argc = max(argc-1, 0);
	argv++;

	switch (num) {
	case 0:
		displaySegment();
		break;
	case 1:
		printf("\nNote: Computer crashed and all work got deleted for array challenges.\n");
		printf("Mrs. Elizabeth instructed me to just do the last one and ignore the rest.\n\n");
		anagram_count();
		break;
	case 2:
		module_2(argc, argv);
		break;
	case 4:
		module_4(argc, argv);
		break;
	case 5:
		module_5(argc, argv);
		break;
	case 7:
		module_7(argc, argv);
		break;
	case 8:
		module_8(argc, argv);
		break;
	case 9:
		module_9(argc, argv);
		break;
	case 11:
		module_11(argc, argv);
		break;
	case 12:
		module_12(argc, argv);
		break;
	}
}

void module_2(int argc, char** argv) {
	int validInputs[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(validInputs) / sizeof(validInputs[0]);

	int num = -1;
	if (argc != 0) num = (int)getnum(*argv);
	if (argc == 0 || !validateInput(num, validInputs, len)) {
		argc = 0;

		printf("Which function do you want to run? Enter a number.\n");
		printf("  1 - exp\n");
		printf("  2 - prnt20\n");
		printf("  3 - prnt02\n");
		printf("  4 - countDigits\n");
		printf("  5 - gcd\n");
		printf("  6 - sum (numbers 1 through n)\n");
		printf("  7 - baseExpAdv (can handle negative exponents)\n");
		printf("  8 - drawTriangle\n");
		printf("  9 - drawTriangleUpsideDown\n> ");

		num = validateInput(validInputs, len);
	}
	putchar('\n');
	argc = max(argc - 1, 0);
	argv++;

	int i1, i2;
	switch (num) {
	case 1:
		if (argc == 0) {
			printf("Enter base: ");
			i1 = (int) getnum(0);
		}
		else i1 = (int) getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		if (argc == 0) {
			printf("Enter exponent: ");
			i2 = (int) getnum(0);
		}
		else i2 = (int) getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		printf("%d", recursion_baseExp(i1, i2));
		break;
	case 2:
		recursion_prnt20(20);
		break;
	case 3:
		recursion_prnt02(20);
		break;
	case 4:
		if (argc == 0) {
			printf("Enter number: ");
			i1 = (int) getnum(0);
		}
		else i1 = (int) getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		printf("%d", recursion_countDigits(i1));
		break;
	case 5:
		if (argc == 0) {
			printf("Enter first number: ");
			i1 = (int) getnum(0);
		}
		else i1 = (int) getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		if (argc == 0) {
			printf("Enter second number: ");
			i2 = (int) getnum(0);
		}
		else i2 = (int) getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		printf("%d", recursion_gcd(i1, i2));
		break;
	case 6:
		if (argc == 0) {
			printf("Enter number: ");
			i1 = (int) getnum(0);
		}
		else i1 = (int) getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		printf("%d", recursion_sum(i1));
		break;
	case 7:
		if (argc == 0) {
			printf("Enter base: ");
			i1 = (int) getnum(0);
		}
		else i1 = (int) getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		if (argc == 0) {
			printf("Enter exponent: ");
			i2 = (int) getnum(0);
		}
		else i2 = (int) getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		printf("%lf", recursion_baseExpAdv(i1, i2));
		break;
	case 8:
		if (argc == 0) {
			printf("Enter number of rows: ");
			i1 = (int) getnum(0);
		}
		else i1 = (int) getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		recursion_drawTriangle(i1);
		break;
	case 9:
		if (argc == 0) {
			printf("Enter number of rows: ");
			i1 = (int) getnum(0);
		}
		else i1 = (int) getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		recursion_drawTriangleUpsideDown(i1);
		break;
	}
}

void module_4(int argc, char** argv) {
	int validInputs[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int len = sizeof(validInputs) / sizeof(validInputs[0]);

	int num = -1;
	if (argc != 0) num = (int)getnum(*argv);
	if (argc == 0 || !validateInput(num, validInputs, len)) {
		argc = 0;

		printf("Which function do you want to run? Enter a number.\n");
		printf("  1 - reverse1 (Book)\n");
		printf("  2 - reverse2 (Book)\n");
		printf("  3 - pointerPalindrome (Book)\n");
		printf("  4 - recursivePointerPalindrome (Book)\n");
		printf("  5 - showList\n");
		printf("  6 - reverseList\n");
		printf("  7 - showChars\n");
		printf("  8 - show2D\n");
		printf("  9 - multiplyArr\n");
		printf("  10 - populateArr\n");
		printf("Note: discussed up to problem 5 in book with Mrs. Elizabeth and Mark\n> ");

		num = validateInput(validInputs, len);
	}
	putchar('\n');
	argc = max(argc - 1, 0);
	argv++;

	int list[10] = { 30241, -5456, 26438, 25040, -21371, 31027, -12430, -32475, 9952, 12594 };
	cc* str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int x[5][3] = {
		{ 11314, -31228, -22631 },
		{ -15288, -15962, -19754 },
		{ 7799, -27141, -1846 },
		{ -13824, 5772, -26500 },
		{ -32313, 7134, -5404 }
	};

	if (num == 5 || num == 6) {
		printf("Original array:");
		show2D(list, 1, 10);
	}
	else if (num == 7) {
		printf("Original string: %s", str);
	}

	switch (num) {
	case 1:
		reverse1();
		break;
	case 2:
		reverse2();
		break;
	case 3:
		pointerPalindrome();
		break;
	case 4:
		recursivePointerPalindrome();
		break;
	case 5:
		showList(list, sizeof(list) / sizeof(list[0]));
		break;
	case 6:
		reverseList(list, sizeof(list) / sizeof(list[0]));
		break;
	case 7:
		showChars(str);
		break;
	case 8:
		printf("Showing pre-initialized array.\n");
		show2D((int*)x, sizeof(x) / sizeof(x[0]), sizeof(x[0]) / sizeof(x[0][0]));
		break;
	case 9:
		multiplyArr();
		break;
	case 10:
		populateArr();
		break;
	}
}

void module_5(int argc, char** argv) {
	int validInputs[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(validInputs) / sizeof(validInputs[0]);

	int num = -1;
	if (argc != 0) num = (int)getnum(*argv);
	if (argc == 0 || !validateInput(num, validInputs, len)) {
		argc = 0;

		printf("Chapter 13, exercise 14: \"Grinch\"\n");
		printf("Chapter 13, exercise 15a: \"3\"\n");
		printf("Chapter 13, exercise 15b: \"0\"\n");
		printf("Chapter 13, exercise 15c: returns index of first letter in s which is not in t.\n\n");

		printf("Which function do you want to run? Enter a number.\n");
		printf("  1 - chapter 13, exercise 18 (remove_filename)\n");
		printf("  2 - chapter 13, project 1 (dictionary smallest and largest word)\n");
		printf("  3 - chapter 13, project 2 (modified remind)\n");
		printf("  4 - chapter 13, project 5 (sum.c)\n");
		printf("  5 - money_sum\n");
		printf("  6 - find_wood\n");
		printf("  7 - strrstr\n");
		printf("  8 - replace\n");
		printf("  9 - removeCow (case insensitive)\n> ");

		num = validateInput(validInputs, len);
	}
	putchar('\n');
	argc = max(argc - 1, 0);
	argv++;

	char i1[100] = {}, i2[100] = {}, i3[100] = {};
	switch (num) {
	case 1:
		if (argc == 0) {
			printf("Enter URL: ");
			fgets(i1, 100, stdin);
			*(i1 + strlen(i1) - 1) = '\0';
		}
		else strncpy(i1, *argv, 100);
		argc = max(argc - 1, 0);
		argv++;

		remove_filename(i1);
		break;
	case 2:
		strings_proj_1();
		break;
	case 3:
		remind_modified();
		break;
	case 4:
		if (argc == 0) printf("This function requires command line arguments as inputs to sum.");
		else strings_sum(argc, argv);
		break;
	case 5:
		money_sum();
		break;
	case 6:
		find_wood();
		break;
	case 7:
		if (argc == 0) {
			const char* original = "How much wood would a woodchuck chuck?";
			printf("Recommended search string: \"%s\"\n", original);
			printf("Enter search string: ");
			fgets(i1, 100, stdin);
			*(i1 + strlen(i1) - 1) = '\0';
		}
		else strncpy(i1, *argv, 100);
		argc = max(argc - 1, 0);
		argv++;

		if (argc == 0) {
			printf("Recommended substring: \"wood\"\n");
			printf("Enter substring: ");
			fgets(i2, 100, stdin);
			*(i2 + strlen(i2) - 1) = '\0';
		}
		else strncpy(i2, *argv, 100);
		argc = max(argc - 1, 0);
		argv++;

		printf("\nOriginal: %s\nSubstring: %s\n", i1, i2);
		printf("String continued from found pointer: %s", strrstr(i1, i2));
		break;
	case 8:
		if (argc == 0) {
			const char* original = "Farmer John lives in Johnstown next to Next to Johnny Highway.";
			printf("Recommended original string: \"%s\"\n", original);
			printf("Enter original string: ");
			fgets(i1, 100, stdin);
			*(i1 + strlen(i1) - 1) = '\0';
		}
		else strncpy(i1, *argv, 100);
		argc = max(argc - 1, 0);
		argv++;

		if (argc == 0) {
			printf("Recommended substring: \"John\"\n");
			printf("Enter substring to remove: ");
			fgets(i2, 100, stdin);
			*(i2 + strlen(i2) - 1) = '\0';
		}
		else strncpy(i2, *argv, 100);
		argc = max(argc - 1, 0);
		argv++;

		if (argc == 0) {
			printf("Recommended substring: \"Benjamin\" or \"Al\"\n");
			printf("Enter substring to replace with: ");
			fgets(i3, 100, stdin);
			*(i3 + strlen(i3) - 1) = '\0';
		}
		else strncpy(i3, *argv, 100);
		argc = max(argc - 1, 0);
		argv++;

		printf("%s\n", replace(i1, i2, i3));
		break;
	case 9:
		if (argc == 0) {
			const char* original = "Farmer John loves momomommmmooooooooooo cow.";
			printf("Recommended moo string: \"%s\"\n", original);
			printf("Enter moo string: ");
			fgets(i1, 100, stdin);
			*(i1 + strlen(i1) - 1) = '\0';
		}
		else strncpy(i1, *argv, 100);
		argc = max(argc - 1, 0);
		argv++;


		printf("Processed output without moo: %s\n", removeCow(i1));
		break;
	}
}

void module_7(int argc, char** argv) {
	int validInputs[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	int len = sizeof(validInputs) / sizeof(validInputs[0]);

	int num = -1;
	if (argc != 0) num = (int)getnum(*argv);
	if (argc == 0 || !validateInput(num, validInputs, len)) {
		argc = 0;

		printf("Which function do you want to run? Enter a number.\n");
		printf("  1 - bitwise book exercises 4 & 5 (RGB)\n");
		printf("  2 - bitwise book exercise 6 (swap bytes)\n");
		printf("  3 - bitwise book exercise 9 (1s in a given character)\n");
		printf("  4 - bitwise book exercise 11\n");
		printf("  5 - bitwise book exercise 12\n");
		printf("  6 - bitwise book exercise 13\n");
		printf("  7 - lowestBitNumber\n");
		printf("  8 - toggleBit\n");
		printf("  9 - lastBitOff\n");
		printf("  10 - bitAdd\n");
		printf("  11 - bitSub\n");
		printf("  12 - bitMul\n");
		printf("  13 - bitDiv\n");
		printf("  14 - bitMod\n> ");

		num = validateInput(validInputs, len);
	}
	putchar('\n');
	argc = max(argc - 1, 0);
	argv++;

	int i1, i2;
	char red, green, blue;
	long rgb;
	u_char r, g, b;
	switch (num) {
	case 1:
		printf("Enter red (0-255): ");
		red = (char)getnum(0);
		printf("Enter green (0-255): ");
		green = (char)getnum(0);
		printf("Enter blue (0-255): ");
		blue = (char)getnum(0);
		rgb = MK_COLOR(red, green, blue);
		r = GET_RED(rgb);
		g = GET_GREEN(rgb);
		b = GET_BLUE(rgb);
		printf("Decimal:\n");
		printf("RGB: %ld, R: %d, G: %d, B: %d\n", rgb, r, g, b);
		printf("Hex:\n");
		printf("RGB: %.6lx, R: %.2x, G: %.2x, B: %.2x\n", rgb, r, g, b);
		break;
	case 2:
		swap_bytes();
		break;
	case 3:
		printf("Enter character: ");
		printf("%d\n", count_ones((u_char) getchar()));
		break;
	case 4:
		printf("Explanation: the operator precedence of == is before &.\n");
		printf("To fix, use parenthesis around the left side of the ==.\n");
		printf("Updated if statement:\n");
		printf("if ((key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT)) == 0)\n");
		break;
	case 5:
		printf("Explanation: bit shifting left by 8 while using a type char essentially zeroes it.\n");
		printf("Instead, cast to an unsigned short first to create two bytes of space.\n");
		printf("Then shift by 8, so the bits on the right half have space to shift over to.\n");
		printf("Updated return statement:\n");
		printf("return (u_short) high_bit << 8 + low_byte;\n");
		break;
	case 6:
		printf("Binary perspective: it clears the lowest set bit.\n");
		printf("Numerical perspective: it finds the largest power of 2 ");
		printf("that divides the number and subtracts it.\n");
		break;
	case 7:
		if (argc == 0) {
			printf("Enter number: ");
			i1 = (int)getnum(0);
		}
		else i1 = (int)getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		i2 = lowestBitNumber(i1);
		printNumAndHex(i1);
		printNumAndHex(i2);
		break;
	case 8:
		if (argc == 0) {
			printf("Enter number: ");
			i1 = (int)getnum(0);
		}
		else i1 = (int)getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		printNumAndHex(i1);

		if (argc == 0) {
			printf("Enter bit number: ");
			i2 = (int)getnum(0);
		}
		else i2 = (int)getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		i2 = toggleBit(i1, i2);
		printNumAndHex(i2);
		break;
	case 9:
		if (argc == 0) {
			printf("Enter number: ");
			i1 = (int)getnum(0);
		}
		else i1 = (int)getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		i2 = lastBitOff(i1);
		printNumAndHex(i1);
		printNumAndHex(i2);
		break;
	case 10:
		if (argc == 0) {
			printf("Enter first number: ");
			i1 = (int)getnum(0);
		}
		else i1 = (int)getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		if (argc == 0) {
			printf("Enter second number: ");
			i2 = (int)getnum(0);
		}
		else i2 = (int)getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		printf("%d", bitAdd(i1, i2));
		break;
	case 11:
		if (argc == 0) {
			printf("Enter first number: ");
			i1 = (int)getnum(0);
		}
		else i1 = (int)getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		if (argc == 0) {
			printf("Enter second number: ");
			i2 = (int)getnum(0);
		}
		else i2 = (int)getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		printf("%d", bitSub(i1, i2));
		break;
	case 12:
		if (argc == 0) {
			printf("Enter first number: ");
			i1 = (int)getnum(0);
		}
		else i1 = (int)getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		if (argc == 0) {
			printf("Enter second number: ");
			i2 = (int)getnum(0);
		}
		else i2 = (int)getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		printf("%d", bitMul(i1, i2));
		break;
	case 13:
		if (argc == 0) {
			printf("Enter first number: ");
			i1 = (int)getnum(0);
		}
		else i1 = (int)getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		if (argc == 0) {
			printf("Enter second number: ");
			i2 = (int)getnum(0);
		}
		else i2 = (int)getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		printf("%d", bitDiv(i1, i2));
		break;
	case 14:
		if (argc == 0) {
			printf("Enter first number: ");
			i1 = (int)getnum(0);
		}
		else i1 = (int)getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		if (argc == 0) {
			printf("Enter second number: ");
			i2 = (int)getnum(0);
		}
		else i2 = (int)getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		printf("%d", bitMod(i1, i2));
		break;
	}
}

void module_8(int argc, char** argv) {
	int validInputs[] = { 1, 2, 3, 4, 5, 6, 7 };
	int len = sizeof(validInputs) / sizeof(validInputs[0]);

	int num = -1;
	if (argc != 0) num = (int)getnum(*argv);
	if (argc == 0 || !validateInput(num, validInputs, len)) {
		argc = 0;

		printf("Which function do you want to run? Enter a number.\n");
		printf("  1 - findmin\n");
		printf("  2 - findsum\n");
		printf("  3 - ispalindrome\n");
		printf("  4 - intToHexAndBin\n");
		printf("  5 - reverse (reverse a string)\n");
		printf("  6 - fibonacci (with static memoization)\n");
		printf("  7 - checkNesting\n> ");

		num = validateInput(validInputs, len);
	}
	putchar('\n');
	argc = max(argc - 1, 0);
	argv++;

	int list[10] = {};
	u_int i1;
	char buf[100] = {};
	switch (num) {
	case 1:
		i1 = sizeof(list) / sizeof(list[0]);
		printf("Enter %d numbers, seperated by newlines or spaces:\n", i1);
		for (u_int i = 0; i < i1; i++) list[i] = (int)getnum(0);
		printf("Min element: %d\n", findmin(list, i1));
		break;
	case 2:
		i1 = sizeof(list) / sizeof(list[0]);
		printf("Enter %d numbers, seperated by newlines or spaces:\n", i1);
		for (u_int i = 0; i < i1; i++) list[i] = (int)getnum(0);
		printf("Sum of elements: %d\n", findsum(list, i1));
		break;
	case 3:
		if (argc == 0) {
			printf("Enter string to check if palindrome: ");
			fgets(buf, 100, stdin);
			*(buf + strlen(buf) - 1) = '\0';
		}
		else strncpy(buf, *argv, 100);
		argc = max(argc - 1, 0);
		argv++;

		printf(ispalindrome((cc*) buf) ? "true" : "false");
		break;
	case 4:
		if (argc == 0) {
			printf("Enter number: ");
			i1 = (u_int)getnum(0);
		}
		else i1 = (u_int)getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		intToHexAndBin(i1);
		break;
	case 5:
		if (argc == 0) {
			printf("Enter string to reverse: ");
			fgets(buf, 100, stdin);
			*(buf + strlen(buf) - 1) = '\0';
		}
		else strncpy(buf, *argv, 100);
		argc = max(argc - 1, 0);
		argv++;

		printf("Original string: %s\n", buf);
		reverse(buf);
		printf("Reversed string: %s\n", buf);
		break;
	case 6:
		printf("Note 1: this program assumes the 1st term is 0 and the 2nd term is 1.\n");
		printf("The fibonacci sequence is also often represented ");
		printf("as the first and second term both being 1.\n\n");
		printf("Note 2: this program can go up to 93 before overflowing.\n\n");
		printf("10 to 90:\n");
		for (int i = 1; i < 10; i++) printf("%d: %lld\n", i*10, fibonacci(i * 10));
		if (argc == 0) {
			printf("\nEnter number: ");
			i1 = (u_int)getnum(0);
		}
		else i1 = (u_int)getnum(*argv);
		argc = max(argc - 1, 0);
		argv++;

		printf("Result: %lld", fibonacci((int)i1));
		break;
	case 7:
		buf[0] = 1;
		while (buf[0]) {
			printf("Enter string to check nesting: ");
			fgets(buf, 100, stdin);
			*(buf + strlen(buf) - 1) = '\0';
			printf("Testing \"%s\": %s\n", buf, checkNesting(buf) ? "true" : "false");
		}
		break;
	}
}

void module_9(int argc, char** argv) {
	int validInputs[] = { 1, 2 };
	int len = sizeof(validInputs) / sizeof(validInputs[0]);

	int num = -1;
	if (argc != 0) num = (int)getnum(*argv);
	if (argc == 0 || !validateInput(num, validInputs, len)) {
		argc = 0;

		printf("Which function do you want to run? Enter a number.\n");
		printf("  1 - kadane 1D\n");
		printf("  2 - kadane 2D\n");
		printf("Note: array values are initialized beforehand for convenience.\n> ");

		num = validateInput(validInputs, len);
	}
	putchar('\n');
	argc = max(argc - 1, 0);
	argv++;

	int arr1D[] = { 6, 4, 2, -1, 2, 2, 3, -7, -1, -7, -4, 2, 7, 2, 4, -4, 5, -2, 5, -7 };
	int arr2D[2][3] = { {1, 2, 5}, {-2, 100, -3} };
	int start_row, end_row, start_col, end_col, res;
	switch (num) {
	case 1:
		printf("Original array:\n");
		show2D(arr1D, 1, sizeof(arr1D) / sizeof(arr1D[0]));
		res = find_greatest_sum(
			arr1D, sizeof(arr1D) / sizeof(arr1D[0]),
			&start_col, &end_col
		);
		printf(
			"\nMax: %d\nStart: %d\nEnd: %d\n",
			res, start_col, end_col
		);
		break;
	case 2:
		printf("Array is 0-indexed and displayed in (row, column) style from the top left\n");
		printf("Original array:\n");
		show2D(
			(int*) arr2D,
			sizeof(arr2D) / sizeof(arr2D[0]),
			sizeof(arr2D[0]) / sizeof(arr2D[0][0])
		);

		res = find_greatest_sum(
			(int*) arr2D,
			sizeof(arr2D) / sizeof(arr2D[0]),
			sizeof(arr2D[0]) / sizeof(arr2D[0][0]),
			&start_row, &end_row, &start_col, &end_col
		);
		printf(
			"Max: %d\nStart: (%d, %d)\nEnd: (%d, %d)\n",
			res, start_row, start_col, end_row, end_col
		);
		break;
	}
}

void module_11(int argc, char** argv) {
	int validInputs[] = { 1, 2, 3, 4 };
	int len = sizeof(validInputs) / sizeof(validInputs[0]);

	int num = -1;
	if (argc != 0) num = (int)getnum(*argv);
	if (argc == 0 || !validateInput(num, validInputs, len)) {
		argc = 0;

		printf("Which function do you want to run? Enter a number.\n");
		printf("  1 - interactive_insersion_sort\n");
		printf("  2 - interactive_qsort\n");
		printf("  3 - interactive_bsearch\n");
		printf("  4 - interactive_custom_bsearch\n> ");

		num = validateInput(validInputs, len);
	}
	putchar('\n');
	argc = max(argc - 1, 0);
	argv++;

	switch (num) {
	case 1:
		interactive_insersion_sort();
		break;
	case 2:
		interactive_qsort();
		break;
	case 3:
		interactive_bsearch();
		break;
	case 4:
		interactive_custom_bsearch();
		break;
	}
}

void module_12(int argc, char** argv) {
	int validInputs[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(validInputs) / sizeof(validInputs[0]);

	int num = -1;
	if (argc != 0) num = (int)getnum(*argv);
	if (argc == 0 || !validateInput(num, validInputs, len)) {
		argc = 0;

		printf("Which function do you want to run? Enter a number.\n");
		printf("  1 - getFsize (of \"file_io_1.txt\")\n");
		printf("  2 - file_io_txt_vs_bin\n");
		printf("  3 - file_io_fill_random\n");
		printf("  4 - file_io_cat_files\n");
		printf("  5 - file_io_hex_display\n");
		printf("  6 - file_io_find_substring\n");
		printf("  7 - file_io_replace\n");
		printf("  8 - file_io_moo\n");
		printf("  9 - file_io_bonus\n> ");

		num = validateInput(validInputs, len);
	}
	putchar('\n');
	argc = max(argc - 1, 0);
	argv++;

	char file[14], original[90], i1[100], i2[100];
	switch (num) {
	case 1:
		printf("File size: %d bytes\n", getFsize("./file_io_1.txt"));
		break;
	case 2:
		file_io_txt_vs_bin();
		break;
	case 3:
		file_io_fill_random();
		break;
	case 4:
		if (argc == 0) printf("This function requires command line arguments to display files.");
		else file_io_cat_files(argc, argv);
		break;
	case 5:
		if (argc == 0) printf("This function requires command line arguments to display a file.");
		else file_io_hex_display(*argv);
		break;
	case 6:
		if (argc < 2) printf("This function requires two command line arguments to find "
			"a substring.\nThe first is a delimiter and the second is the occurrence number.");
		else file_io_find_substring(*argv, (int) getnum(*(argv+1)));
		break;
	case 7:
		strcpy(file, "file_io_7.txt");
		strcpy(original, "Farmer John lives in Johnstown next to Next to Johnny Highway.");
		printf("Original string in \"%s\": \"%s\"\n\n", file, original);

		if (argc == 0) {
			printf("Recommended substring: \"John\"\n");
			printf("Enter substring to remove: ");
			fgets(i1, 100, stdin);
			*(i1 + strlen(i1) - 1) = '\0';
		}
		else strncpy(i1, *argv, 100);
		argc = max(argc - 1, 0);
		argv++;

		if (argc == 0) {
			printf("Recommended substring: \"Benjamin\" or \"Al\"\n");
			printf("Enter substring to replace with: ");
			fgets(i2, 100, stdin);
			*(i2 + strlen(i2) - 1) = '\0';
		}
		else strncpy(i2, *argv, 100);
		argc = max(argc - 1, 0);
		argv++;

		file_io_replace(file, i1, i2);
		break;
	case 8:
		strcpy(file, "file_io_8.txt");
		strcpy(original, "Momomommmmooooooooooo Mommomomommmmooooooooooomy "
			"Cow loves baby comomomommmmooooooooooow.");
		printf("Original string in \"%s\": \"%s\"\n\n", file, original);
		file_io_moo(file);
		break;
	case 9:
		file_io_bonus();
		break;
	}
}

int validateInput(int* arr, int len) {
	int i = (int) getnum(0);
	while (!validateInput(i, arr, len)) {
		printf("\nSorry, invalid input. Please try again.\n> ");
		i = (int)getnum(0);
	}
	return i;
}

bool validateInput(int num, int* arr, int len) {
	for (int* i = arr; i < arr + len; i++) {
		if (num == *i) return true;
	}
	return false;
}
