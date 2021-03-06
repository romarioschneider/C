#include <stdio.h>
#define TWIDTH 20 //������ ���������, ��������
#define TABLEN 8 //������ ���������
#define MAXLEN 1000 //������������ ����� �������  ������
#define YES  1 //����� �� �� � "������������" ������� ������: YES - ������� ��������, �������� ������� �������
#define NO 0 //������� � ������ ������ ������������

int getlen();
void fold(int len);

char line[MAXLEN];
int set_new_line = NO; //���� �� ������ ������ ��������� �������� ����� ������

int main() {
	
	int len, i;
	
	// ���� ������ ������ �� �����
	while((len = getlen()) != 0) {

		//���� ����� ������ ��������� TWIDTH - �������� fold() ��� ����������� ������ 
		if (len > TWIDTH) 
			fold(len);
		//��� ����������� �������� ����������� ������
		else {
			i = 0;
			while(i < len) {
				printf("%c", line[i]);
				++i;
			}
		}
	if (set_new_line != NO) //��. ����������� � fold()
		printf("\n");
	}
	
	return 0;
}

/* ������ �������� ����� ������ � ������ ������� ������ � ������ */
int getlen() {

	int c, len = 0;
	
	/* ����������� ������� �������� � ������ ���� �� ��������� ������ ����� ������ � ���������� ������� � ������ */
	while((c = getchar()) != EOF && c != '\n') {
	
		/* ��������� ������ �������� - �������� �-� detab() � �������� �� ����� ������� ������� � ������� */
		if (c == '\t') 
			len = detab(len);
		else {
			line[len] = c;
			++len;
		}
	}
	
	return len;
}

/* ������ ������ �������� �������� ����������� = TABLEN ��������� �������� */
int detab (int i) {
	
	/* ��������� � ������� ������� �-�� �������� �� ������� ������� �������� */
	int shift = i + (TABLEN - i % TABLEN);
	
	while (i < shift) {
		line[i] = ' ';
		++i;
	}
	/* ���������� �������� ������� � ������� ����� ������� */
	return i;
	
}
//������� ������������ ������ ����� ������� ����� ������� #TWIDTH ������� ����� ������
void fold (int len) {
	
	int i = 0;
	int ii = 0;
	int is_head = NO; //��������� �� �� � ������ (����������) ��������� ������
	//���� �� ��������� �� ���� �������� ��������� ��������� ������� line[]
	while (i < len) {
		//��������� ���� ��������� - �������� ����� �������, ������������� ���� ������� ��������� ��� ���������� ��������� ��������
		if (ii == TWIDTH) {
			printf("\n");
			is_head = NO;
			ii = 0;
		}
		//���������� ��������� �������
		if (is_head == NO && line[i] == ' ') {
			set_new_line = NO; //���� ����� ������� ������ ������, �� ������ ���� �������, �� � main() ����� ������� �� ��������
			++i;
		}
		else {
			//��������� ������ ������������ ������ - �������� ��� � ������������� ���� ����� ������� ��� ���������� ������ �������
			is_head = YES;
			printf("%c", line[i]);
			set_new_line = YES;
			++ii;
			++i;
		}
	}
}	