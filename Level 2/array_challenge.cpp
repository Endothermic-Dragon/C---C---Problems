// Standard libraries
#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "default_library.h"
#include "array_challenge.h"

// Computer crashed and all work got deleted for array challenges
// Mrs. Elizabeth said to just do the last one and ignore the rest

void anagram_count() {
	char words[numWords][100] = { "aaabc", "cbaad", "aadbc", "cbaaa", "cdcdcd", "dccdcd", "abcaa" };
	char freq_table[numWords][26] = { 0 };
	int currInd = 0;
	for (int i = 0; i < numWords; i++) {
		char* wordChar = words[i];
		for (int j = 0; j < 26; j++) freq_table[currInd][j] = 0;
		while (*wordChar) {
			(freq_table[currInd][*wordChar - 'a'])++;
			wordChar++;
		}
		int anagramVal = currInd + 1;
		for (int j = 0; j < currInd; j++) {
			bool success = true;
			for (char k = 0; k < 26; k++) {
				if (freq_table[j][k] != freq_table[currInd][k]) {
					success = false;
					break;
				}
			}
			if (success) {
				currInd--;
				anagramVal = j + 1;
				break;
			}
		}
		currInd++;
		printf("%s, %d\n", words[i], anagramVal);
	}
}
