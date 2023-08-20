// Standard libraries
#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "default_library.h"
#include "subarray_sum.h"

int find_greatest_sum(int* list, int n) {
	int maxSum = 0, runSum = 0;
	for (int i = 0; i < n; i++) {
		runSum = max(runSum + *(list + i), 0);
		maxSum = max(maxSum, runSum);
	}
	return maxSum;
}

int find_greatest_sum(int* list, int n, int* start, int* end) {
	int maxSum = 0, runSum = 0, currStart = 0;
	for (int i = 0; i < n; i++) {
		if (runSum + *(list + i) > 0) runSum += *(list + i);
		else {
			runSum = 0;
			currStart = i + 1;
		}
		if (runSum > maxSum) {
			maxSum = runSum;
			*start = currStart;
			*end = i;
		}
	}
	return maxSum;
}

int find_greatest_sum(int* list, int rows, int cols) {
	int* arr = (int*)calloc((u_ll)rows * cols, sizeof(int));
	int* p_sums = (int*)calloc(cols, sizeof(int));
	if (arr != 0 && p_sums != 0) {
		memcpy(arr, list, (u_ll)rows * cols * sizeof(int));
		for (u_ll i = 1; i < rows; i++) {
			for (u_ll j = 0; j < cols; j++) {
				*(arr + cols * i + j) += *(arr + cols * (i - 1) + j);
			}
		}
		int maxSum = 0;
		for (u_ll i_1 = 0; i_1 < rows; i_1++) {
			for (u_ll i_2 = i_1; i_2 < rows; i_2++) {
				for (u_ll j = 0; j < cols; j++) {
					*(p_sums + j) = *(arr + cols * i_2 + j) - (i_1 == 0 ? 0 : *(arr + cols * (i_1 - 1) + j));
				}
				maxSum = max(maxSum, find_greatest_sum(p_sums, cols));
			}
		}
		free(arr);
		return maxSum;
	}
	return find_greatest_sum(list, rows, cols);
}


int find_greatest_sum(int* list, int rows, int cols, int* start_row, int* end_row, int* start_col, int* end_col) {
	int* arr = (int*)calloc((u_ll)rows * cols, sizeof(int));
	int* p_sums = (int*)calloc(cols, sizeof(int));
	int currMax, c_1, c_2;
	if (arr != 0 && p_sums != 0) {
		memcpy(arr, list, (u_ll)rows * cols * sizeof(int));
		for (u_ll i = 1; i < rows; i++) {
			for (u_ll j = 0; j < cols; j++) {
				*(arr + cols * i + j) += *(arr + cols * (i - 1) + j);
			}
		}
		int maxSum = 0;
		for (u_ll i_1 = 0; i_1 < rows; i_1++) {
			for (u_ll i_2 = i_1; i_2 < rows; i_2++) {
				for (u_ll j = 0; j < cols; j++) {
					*(p_sums + j) = *(arr + cols * i_2 + j) - (i_1 == 0 ? 0 : *(arr + cols * (i_1 - 1) + j));
				}
				currMax = find_greatest_sum(p_sums, cols, &c_1, &c_2);
				if (currMax > maxSum) {
					maxSum = currMax;
					*start_row = (int) i_1;
					*end_row = (int) i_2;
					*start_col = c_1;
					*end_col = c_2;
				}
			}
		}
		free(arr);
		return maxSum;
	}
	return find_greatest_sum(list, rows, cols);
}
