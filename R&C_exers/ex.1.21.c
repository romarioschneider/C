#include <stdio.h>
#define TABLEN 8
#define MAXLEN 1000

int getlen();
int entab(int s);
int space_c(int i);

char line[MAXLEN];

int main() {
	
	int len, i;
	
	/* ���� ������ ������ �� ����� ... */
	while((len = getlen()) != 0) {
		/* ���� ������ ������� �� ����� �������� - �������� entab */
		if (len == space_c(len))
			len = entab(len);
		/* ����������� ������� �� ������ ������ ��� �������������� �������� �������� ���������� ������, ���� ��� ���� ������� ������� */
		i = 0;
		while (i < len) {
			printf("%c", line[i]);
			++i;
		}
	printf("\n");
	}
	
	return 0;
}

/* ������ �������� ����� ������ � ������ ������� ������ � ������ */
int getlen() {

	int c, len = 0;
	
	/* ����������� ������� �������� � ������ ���� �� ���������� ������ ����� ������ � ���������� ������� � ������ */
	while((c = getchar()) != EOF && c != '\n') {
			line[len] = c;
			++len;
	}
	
	return len;
}

/* ������� ������ �������� ��������� ����������� = TABLEN ��������� �������� */
int entab (int s) {
	
	/* ��������� �-�� �����, ���������� ������� */
	int count_tab = s / TABLEN;
	int i = 0;
	/* ���� ������� �� ������� ��������� - ������ ���� ��� ������� �� ��������� ������� ��������� � ���� �������� ��� ���� ��� */
	if (s % TABLEN != 0)
		++count_tab;
	
	while (i < count_tab) {
		line[i] = '\t';
		++i;
	}
	
	return count_tab;
}

/* �-� �������� ���������� �������� � ������ */
int space_c(int i) {

	int ii = 0;
	int count = 0;
	
	while (ii < i) {
		if (line[ii] == ' ')
			++count;
		++ii;
	}

	return count;
}
