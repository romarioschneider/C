#include <stdio.h>
#define MAXLEN 1000
#define TRESHOLD 80 /* ����� ��� ����� ������, ������� ����� ���������� �� ������ � �������� */

int getlen(char line[]);

int main() {
	
	int len = 0;
	char line[MAXLEN];
	
/* ���� ���� ������ �� ������ ��������� �� �����, ���� ��� �����, ��� TRESHOLD - �������� � ����� */
	while((len = getlen(line)) != 0) {
		if (len > TRESHOLD)
			printf("%s\n", line);
	}
	return 0;
}


/* ������� �������� ����� ������ � ������ �������� ������ � ������ */
int getlen(char c_array[]) {
	int c, len = 0;
	/* ����������� ������� �������� � ������ ���� �� ���������� ������ ����� ������ � ���������� ������� � ������ */
	while((c = getchar()) != EOF && c != '\n') {
		c_array[len] = c;
		++len;
	}
	/* ��������� � ����� ������ � ��� ������ '\n' */
	if (c == '\n') {
		++len;
	}

	return len;
}