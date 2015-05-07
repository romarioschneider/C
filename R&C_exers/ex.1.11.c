#include <stdio.h>

#define IN  1
#define OUT 0

/* ���� �� ������� ������ 1 ������, �� �� ������������� �������� '\n' - ��������� �������� ������ �-�� ����� = 1, ����������� wc ������� 0 */
/* �������� ��������� ����� �������� ����� ����������� ���. ������ ������ ��������� � ������������� ����� �������. wc � ��� ��������� ����� ������ ���������� */

main () {
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\t' || c == '\n')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	if (nl == 0 && nc != 0)
		++nl;
	printf("nc = %d, nw = %d, nl = %d\n", nc, nw, nl);
}