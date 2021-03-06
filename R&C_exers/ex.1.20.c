#include <stdio.h>
#define TABLEN 8
#define MAXLEN 1000

int getlen();
int detab(int i);

char line[MAXLEN];

int main() {
	
	int len, i;
	
	/* ���� ������ ������ �� ����� ... */
	while((len = getlen()) != 0) {
		i = 0;
		/* ����������� ������� �� ������ ������ �� ������������� �������� �������� ���������� ������, ���� ��� ���� ������� ������� */
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
	
	/* ����������� ������� �������� � ������ ���� �� ��������� ������ ����� ������ � ���������� ������� � ������ */
	while((c = getchar()) != EOF && c != '\n') {
	
		/* ��������� ������ ��������� - �������� �-� detab() � �������� �� ����� ������� ������� � ������� */
		if (c == '\t') 
			len = detab(len);
		else {
			line[len] = c;
			++len;
		}
		
	}
	
	return len;
}

/* ������� ������ �������� ��������� ����������� = TABLEN ��������� �������� */
int detab (int i) {
	
	/* ���������� � ������� ������� �-�� �������� �� ������� ������� ��������� */
	int shift = i + (TABLEN - i % TABLEN);
	
	while (i < shift) {
		line[i] = ' ';
		++i;
	}
	/* ���������� �������� ������� � ������� ����� �������� */
	return i;
	
}