#include <iostream>
#include <string.h>
#include "remind.h"
#define MAX_REMIND 50
#define MSG_LEN 60

void remind_modified() {
	char reminders[MAX_REMIND][MSG_LEN + 3];
	char day_str[12], msg_str[MSG_LEN + 1];
	int month, day, hour, minute, i, j, num_remind = 0;

	printf("Input format: month/day hour:minute message. Enter 0 to stop.\n");
	for (;;) {
		if (num_remind == MAX_REMIND) {
			printf("No space left --\n");
			break;
		}

		printf("Enter day and reminder: ");
		scanf_s("%d", &month);
		if (month == 0)
			break;
		scanf_s("/%d", &day);
		scanf_s(" %d", &hour);
		scanf_s(":%d", &minute);
		if (day < 0 || day > 31) {
			printf("Invalid date entered.\n");
			continue;
		}
		sprintf_s(day_str, "%0.2d/%0.2d %0.2d:%0.2d", month, day, hour, minute);
		read_line(msg_str, MSG_LEN);

		for (i = 0; i < num_remind; i++)
			if (strcmp(day_str, reminders[i]) < 0)
				break;
		for (j = num_remind; j > i; j--)
			strcpy_s(reminders[j], reminders[j - 1]);
		strcpy_s(reminders[i], day_str);
		strcat_s(reminders[i], msg_str);

		num_remind++;
	}
	printf("\nDay Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf("%s\n", reminders[i]);
}
int read_line(char str[], int n) {
	int ch, i = 0;
	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = (char) ch;
	str[i] = '\0';
	return i;
}
