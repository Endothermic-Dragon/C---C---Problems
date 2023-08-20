#define _CRT_SECURE_NO_WARNINGS

// Standard libraries
#include <iostream>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "default_library.h"
#include "strings.h"
#include "file_io.h"

// For random
#include <time.h>
#include <stdlib.h>

int getFsize(cc* filename) {
	FILE* file = fopen(filename, "r");
	fseek(file, 0, SEEK_END);
	// Make sure to include terminating character in file size
	int fileSize = (int) ftell(file) + 1;
	fclose(file);
	return fileSize;
}

void file_io_txt_vs_bin() {
	FILE* file = fopen("./file_io_2_out.txt", "w");
	for (int i = 100; i < 200; i += 10) {
		fprintf(file, "%d,", i);
	}
	fprintf(file, "%d", 200);
	fclose(file);
	printf("Text file size: %d bytes\n", getFsize("./file_io_2_out.txt"));

	file = fopen("./file_io_2_out.bin", "w");
	u_char binData[21] = {};
	for (int i = 0; i < 10; i++) {
		binData[i * 2] = (u_char) (100 + i * 10);
		binData[i * 2 + 1] = ',';
	}
	binData[20] = 200;
	fwrite(binData, sizeof(u_char), 21, file);
	fclose(file);
	printf("Binary file size: %d bytes\n", getFsize("./file_io_2_out.bin"));
}

void file_io_fill_random() {
	srand((u_int)time(0));

	FILE* file = fopen("./file_io_3_in.txt", "r");
	int rows = (int)getnum(0, file);
	int cols = (int)getnum(0, file);
	fclose(file);
	printf("(%d, %d)", rows, cols);

	file = fopen("./file_io_3_out.txt", "w");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols - 1; j++) {
			fprintf(file, "%d ", rand() % 10);
		}
		fprintf(file, "%d\n", rand() % 10);
	}
	fclose(file);
}

void file_io_cat_files(int argc, char** argv) {
	FILE* file;
	for (int i = 0; i < argc; i++) {
		file = fopen(*(argv + i), "r");
		if (file == NULL) {
			printf("Unable to open file %s\n", argv[i]);
			continue;
		}
		while (!feof(file)) {
			putchar(fgetc(file));
		}
		putchar('\n');
		fclose(file);
	}
}

void file_io_hex_display(cc* fname){
	printf("Offset               Bytes               Characters\n");
	printf("------   -----------------------------   ----------\n");

	FILE* file = fopen(fname, "rb");
	char* bytes = (char*)malloc(sizeof(char) * 10);
	if (bytes == NULL) return;
	int readBytes, count = 0;
	while (true) {
		readBytes = (int) fread(bytes, sizeof(char), 10, file);
		printf("%6d   ", count++ * 10);
		for (int i = 0; i < readBytes; i++) printf("%.2X ", *(bytes + i));
		for (int i = readBytes; i < 10; i++) printf("   ");
		printf("   ");
		for (int i = 0; i < readBytes; i++) {
			if (isprint(*(bytes + i))) printf("%c", *(bytes + i));
			else printf(".");
		}
		for (int i = readBytes; i < 10; i++) putchar(' ');
		putchar('\n');
		if (feof(file)) break;
	}

	free(bytes);
}

void file_io_find_substring(cc* delim, int num) {
	int size = getFsize("file_io_6.txt");
	char* str = (char*)calloc(size, sizeof(char));
	if (str == NULL) return;
	FILE* file = fopen("file_io_6.txt", "r");
	fread(str, sizeof(char), size, file);
	fclose(file);
	int len = (int) strlen(delim), count = 1;
	char* next;
	while (true) {
		next = strstr(str, delim);
		if (count == num) {
			if (next != 0) *next = '\0';
			printf("%s", str);
			return;
		} else if (next == 0) {
			printf("Unable to find substring, reached end of file.");
			return;
		} else {
			str = next + len;
			count++;
		}
	}
}

void file_io_replace(cc* fname, cc* oldStr, cc* newStr) {
	int size = getFsize(fname);
	char* str = (char*)calloc(size, sizeof(char));
	if (str == NULL) return;
	FILE* file = fopen(fname, "r");
	fread(str, sizeof(char), size, file);
	fclose(file);
	printf("Original text: %s\n", str);

	char* res = replace((cc*) str, oldStr, newStr);
	printf("Updated text: %s\n", res);

	file = fopen(fname, "w");
	fprintf(file, res);
	fclose(file);
	printf("File updated!\n");
}

void file_io_moo(cc* fname) {
	int size = getFsize(fname);
	char* str = (char*)calloc(size, sizeof(char));
	if (str == NULL) return;
	FILE* file = fopen(fname, "r");
	fread(str, sizeof(char), size, file);
	fclose(file);
	printf("Original text: %s\n", str);

	cc* res = removeCow((cc*)str);
	printf("Updated text: %s\n", res);

	file = fopen(fname, "w");
	fprintf(file, res);
	fclose(file);
	printf("File updated!\n");
}

void file_io_bonus() {
	// Have to allocate an extra byte with '\0' or free complains
	// Throws "HEAP CORRUPTION DETECTED" error otherwise
	char* strBufBackground = (char*)calloc(7, sizeof(char));
	char* strBufColor = (char*)calloc(7, sizeof(char));
	char* lineBuf = (char*)calloc(101, sizeof(char));
	int R, G, B;

	printf("Updating background color.\n");
	printf("Enter red value: ");
	R = (int)getnum(0);
	printf("Enter green value: ");
	G = (int)getnum(0);
	printf("Enter blue value: ");
	B = (int)getnum(0);
	sprintf(strBufBackground, "%.2x%.2x%.2x", R, G, B);

	printf("Updating text color.\n");
	printf("Enter red value: ");
	R = (int)getnum(0);
	printf("Enter green value: ");
	G = (int)getnum(0);
	printf("Enter blue value: ");
	B = (int)getnum(0);
	sprintf(strBufColor, "%.2x%.2x%.2x", R, G, B);

	FILE* file = fopen("bonus.html", "r+");
	int begin = 0;
	while (strstr(lineBuf, "body") == NULL) {
		if (feof(file)) return;
		begin = ftell(file);
		fgets(lineBuf, 100, file);
	}
	char* loc = lineBuf, *prevLoc = lineBuf;

	if ((loc = strstr(prevLoc, "background-color:#")) != NULL) {
		loc += strlen("background-color:#");
		prevLoc = loc;
		memcpy(loc, strBufBackground, 6);
	} else if ((loc = strstr(prevLoc, "background-color: #")) != NULL) {
		loc += strlen("background-color: #");
		prevLoc = loc;
		memcpy(loc, strBufBackground, 6);
	}

	if ((loc = strstr(prevLoc, "color:#")) != NULL) {
		loc += strlen("color:#");
		memcpy(loc, strBufColor, 6);
	} else if ((loc = strstr(prevLoc, "color: #")) != NULL) {
		loc += strlen("color: #");
		memcpy(loc, strBufColor, 6);
	}
	printf(lineBuf);

	fseek(file, begin, SEEK_SET);
	fprintf(file, "%s", lineBuf);
	fclose(file);

	free(strBufBackground);
	free(strBufColor);
	free(lineBuf);
}
