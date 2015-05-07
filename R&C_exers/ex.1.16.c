#include <stdio.h>

int getlen();

int main() {
	int len, max = 0;
	
	while(( len = getlen()) > 0)
		if (len > max) {
			max = len;
		}
	printf("max length = %d\n", max);
	return 0;
}
	
/* ������� �������� ����� ������ */
int getlen() {
	int c, len = 0;
	/* ����������� ������� �������� � ������ ���� �� ���������� ������ ����� ������ */
	while((c = getchar()) != EOF && c != '\n')
		++len;
	/* ��������� � ����� ������ � ��� ������ '\n' */
	if (c == '\n')
		++len;
	return len;
}
	
		