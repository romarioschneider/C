#include <stdio.h>
#define MAXLEN 1000

int getlen(char line[]);
void reverse(char line[], int line_lenght);

int main() {
	
	int len, i;
	char line[MAXLEN];
	
	/* ���� �������� ������ �� ������ ... */
	while((len = getlen(line)) != 0) {
		reverse(line, len);
		i = 0;
		
		/* ����������� ������� �� ������ ������ ��� �������������� ��������� �������� ���������� ������, ���� ��� ���� ������� ������� */
		while (i < len) {
			printf("%c", line[i]);
			++i;
		}
	printf("\n");
	}
		
	return 0;
}
		
/* ������ �������� ����� ������ � ������ ������� ������ � ������ */
int getlen(char c_array[]) {

	int c, len = 0;
	
	/* ����������� ������� �������� � ������ ���� �� ��������� ������ ����� ������ � ���������� ������� � ������ */
	while((c = getchar()) != EOF && c != '\n') {
		c_array[len] = c;
		++len;
	}
	
	return len;
}

/* �-��� ���������� ���������� ��������� � �������� ������� */
void reverse(char c_array[], int array_len) {
	
	/* ��������� ������ ��� �������������� �������� �������� */
	char tmp[MAXLEN];
	int i = 0;
	
	/* �������� ������� ������� �� ������� main � ������ tmp � �������� ������� */
	while (i < array_len) {
		tmp[i] = c_array[array_len - 1 - i];
		++i;
	}
	/* �������� ������� �� ������� tmp ������� � �������� ������ */
	i = 0;
	while (i < array_len) {
		c_array[i] = tmp[i];
		++i;
	}
		
}		