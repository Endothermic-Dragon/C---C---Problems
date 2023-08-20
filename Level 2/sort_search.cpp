// Standard libraries
#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "default_library.h"
#include "sort_search.h"

bool verify_order(int* list, int n) {
	for (int i = 1; i < n; i++) {
		if (*(list + i) < *(list + i - 1)) return false;
	}
	return true;
}

void insersion_sort(int* list, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (*(list + j) < *(list + j - 1)) {
				*(list + j) ^= *(list + j - 1);
				*(list + j - 1) ^= *(list + j);
				*(list + j) ^= *(list + j - 1);
			} else break;
		}
	}
}

void interactive_insersion_sort() {
	printf("How many numbers do you want in your unsorted list? ");
	int n = (int)getnum(0);
	int* list = (int*)calloc(n, sizeof(int));
	if (list != 0) {
		printf("Enter your list elements: ");
		for (int i = 0; i < n; i++) *(list + i) = (int)getnum(0);
		insersion_sort(list, n);
		putchar('[');
		for (int i = 0; i < n - 1; i++) {
			printf("%d, ", *(list + i));
		}
		printf("%d]\n", *(list + n - 1));
		printf("Ordered: %s\n", verify_order(list, n) ? "true" : "false");
	}
}

int compare(const void* p, const void* q) {
	return *(int*)p - *(int*)q;
}

void interactive_qsort() {
	printf("How many numbers do you want in your unsorted list? ");
	int n = (int)getnum(0);
	int* list = (int*)calloc(n, sizeof(int));
	if (list != 0) {
		printf("Enter your list elements: ");
		for (int i = 0; i < n; i++) *(list + i) = (int)getnum(0);
		qsort(list, n, sizeof(int), compare);
		putchar('[');
		for (int i = 0; i < n - 1; i++) {
			printf("%d, ", *(list + i));
		}
		printf("%d]\n", *(list + n - 1));
		printf("Ordered: %s\n", verify_order(list, n) ? "true" : "false");
	}
}

void interactive_bsearch() {
	printf("How many numbers do you want in your (sorted) list? ");
	int n = (int)getnum(0);
	int* list = (int*)calloc(n, sizeof(int));
	if (list != 0) {
		printf("Enter your list elements: ");
		for (int i = 0; i < n; i++) *(list + i) = (int)getnum(0);
		printf("Enter the element you want to find: ");
		int el = (int)getnum(0);
		int* foundItem = (int*)bsearch(&el, list, n, sizeof(int), compare);
		if (foundItem == 0) printf("Not found. Returned null pointer.\n");
		else printf("Element found at index %d.\n", (int)(foundItem - list));
	}
}

int* custom_bsearch(int* start, int* end, int target) {
	int* mid = start + (end - start) / 2;
	if (target == *mid) {
		return mid;
	} else if (start == mid) {
		return 0;
	} else if (target > *mid) {
		return custom_bsearch(mid, end, target);
	} else {
		return custom_bsearch(start, mid, target);
	}
}

int* custom_bsearch_wrapper(int target, int* list, int size) {
	return custom_bsearch(list, list + size, target);
}

void interactive_custom_bsearch() {
	printf("How many numbers do you want in your (sorted) list? ");
	int n = (int)getnum(0);
	int* list = (int*)calloc(n, sizeof(int));
	if (list != 0) {
		printf("Enter your list elements: ");
		for (int i = 0; i < n; i++) *(list + i) = (int)getnum(0);
		printf("Enter the element you want to find: ");
		int el = (int)getnum(0);
		int* foundItem = custom_bsearch_wrapper(el, list, n);
		if (foundItem == 0) printf("Not found. Returned null pointer.\n");
		else printf("Element found at index %d.\n", (int)(foundItem - list));
	}
}
