// Standard libraries
#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "default_library.h"
#include "strings.h"
#pragma warning(disable:4996)

void remove_filename(char* url) {
	char* p = strrchr(url, '/');
	*p = '\0';
	printf("%s", url);
}

void strings_proj_1() {
	cc strMaxLen = 21;
	char arr[strMaxLen] = { 0 };
	char firstWord[strMaxLen] = { 127, 0 };
	char lastWord[strMaxLen] = { 0 };
	char c;

	printf("Reading words until four letter word encountered.\n");
	while (strlen(arr) != 5) {
		fgets(arr, 20, stdin);
		c = (char) strncmp(arr, firstWord, strMaxLen);
		if (c < 0) {
			// Fix "The prior call to 'strncpy' might not zero-terminate string 'firstWord'."
			*firstWord = '\0';
			strncat(firstWord, arr, strMaxLen - strlen(firstWord));
		}
		c = (char) strncmp(arr, lastWord, strMaxLen);
		if (c > 0) {
			// Fix "The prior call to 'strncpy' might not zero-terminate string 'firstWord'."
			*lastWord = '\0';
			strncat(lastWord, arr, strMaxLen - strlen(lastWord));
		}
	}

	printf("\n\nSmallest word: %s", firstWord);
	printf("Longest word: %s", lastWord);
}

void strings_sum(int argc, char** argv) {
	int sum = 0;
	int currNum = 0;
	for (int i = 0; i < argc; i++) {
		u_ll argLen = strlen(*(argv + i));
		for (u_int j = 0; j < argLen; j++) {
			currNum *= 10;
			currNum += *(*(argv + i) + j) - '0';
		}
		sum += currNum;
		currNum = 0;
	}
	printf("Total: %d", sum);
}

void money_sum() {
	double vals[3];
	for (int i = 0; i < 3; i++) {
		printf("Value %d: ", i + 1);
		vals[i] = getnum(0);
	}
	char buf[100];
	sprintf_s(buf, "The average of $%.2lf, $%.2lf, and $%.2lf = $%.2lf", vals[0], vals[1], vals[2], (vals[0] + vals[1] + vals[2]) / 3);
	printf(buf);
}

// Skipped rest of part 1 as per Mrs. Elizabeth's instructions

void find_wood() {
	cc* sentence = "How much wood would a woodchuck chuck?";
	cc* fi = sentence;
	cc* word = "wood";
	printf("Found wood at:\n");
	while ((fi = strstr(fi + strlen(word), word)) != NULL) {
		printf("%p %d\n", fi, (int)(fi - sentence));
	}
}

// Mrs. Elizabeth wanted me to reverse the strings before searching
// Don't want to modify the inputs
cc* strrstr(cc* sentence, cc* substr) {
	char* np;

	// Reverse sentence
	char* start = (char*)calloc(strlen(sentence) + 1, sizeof(char));
	if (start == NULL) return (char*) "Not enough space to run.";
	for (u_int i = 0; i < strlen(sentence); i++) {
		np = start + i;
		*np = *(sentence + strlen(sentence) - 1 - i);
	}
	// Called calloc
	// np = start + strlen(sentence);
	// *np = '\0';

	// Reverse substr
	char* bwsubstr = (char*)calloc(strlen(substr) + 1, sizeof(char));
	if (bwsubstr == NULL) return "Not enough space to run.";
	for (u_int i = 0; i < strlen(substr); i++) {
		np = bwsubstr + i;
		*np = *(substr + strlen(substr) - 1 - i);
	}
	// Called calloc
	// np = bwsubstr + strlen(bwsubstr);
	// *np = '\0';

	// Return pointer in original sentence
	int dist = (int)(strstr(start, bwsubstr) - start);
	cc* retP = sentence + strlen(sentence) - strlen(substr) - dist;
	return retP;
}

char* replace(cc* sentence, cc* oldStr, cc* newStr) {
	int numOc = 0;
	char* start = (char*)sentence - strlen(oldStr);
	int* locOc = (int*)calloc(strlen(sentence) / strlen(oldStr), sizeof(int));
	if (locOc == NULL) return (char*)"Not enough space to run.";
	int iLocOc = 0;
	while ((start = strstr(start + strlen(oldStr), oldStr)) != NULL) {
		*(locOc + iLocOc) = (int) (start - sentence);
		numOc++;
		iLocOc++;
	}
	*(locOc + iLocOc) = (int) strlen(sentence) + 1;
	iLocOc++;
	// Don't count over and over again
	int oldStrLen = (int) strlen(oldStr);
	int newStrLen = (int) strlen(newStr);

	// New sentence buffer
	char* newSentence = (char*)calloc(strlen(sentence) + ((ll) newStrLen - oldStrLen) * numOc + (ll) 1, sizeof(char));
	if (newSentence == NULL) return (char*) "Not enough space to run.";
	char* curr = newSentence;

	memcpy(curr, sentence, *locOc);
	curr += *locOc + (ll) newStrLen;
	memcpy(curr - newStrLen, newStr, newStrLen);
	for (int i = 1; i < iLocOc; i++) {
		memcpy(curr, sentence + *(locOc + i - 1) + oldStrLen, (ll) *(locOc + i) - *(locOc + i - 1) - oldStrLen);
		curr += (ll) *(locOc + (ll) i) - *(locOc + i - 1) - oldStrLen+newStrLen;
		memcpy(curr - newStrLen, newStr, newStrLen);
	}

	free(locOc);
	return newSentence;
}

char* stristr(cc* haystack, cc* needle) {
	int c = tolower((unsigned char)*needle);
	if (!c)
		return (char*)haystack;
	for (; *haystack; haystack++) {
		if (tolower((unsigned char)*haystack) == c) {
			for (size_t i = 0;;) {
				if (!needle[++i])
					return (char*)haystack;
				if (tolower((unsigned char)haystack[i]) != tolower((unsigned char)needle[i]))
					break;
			}
		}
	}
	return NULL;
}

int strincmp(char* a, char* b, int n)
{
	for (int i = 0; i < n; i++, a++, b++) {
		int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
		if (d != 0 || *a == 0) return d;
	}
	return 0;
}

cc* removeCow(cc* sentence) {
	cc* maxP = (cc*)sentence + strlen(sentence);
	cc* repS = "moo";
	char* fixed = (char*)calloc(strlen(sentence) + 1, sizeof(char));
	if (fixed == NULL) return "Not enough space to run.";
	char* writeP = fixed;
	cc* currP = stristr(sentence, repS);
	if (currP == NULL) return sentence;
	strncpy(writeP, sentence, currP - sentence);
	writeP += currP - sentence;
	currP += 3;
	while (currP < maxP) {
		*writeP = *currP;
		writeP++;
		currP++;
		if (strincmp(writeP - 3, (char*) repS, 3) == 0) writeP -= 3;
	}
	*writeP = '\0';
	fixed = (char*) realloc(fixed, strlen(fixed) + 1);
	return (cc*) fixed;
}
