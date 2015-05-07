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
	
/* функция подсчета длины строки */
int getlen() {
	int c, len = 0;
	/* увеличиваем счетчик символов в строке пока не встретится символ новой строки */
	while((c = getchar()) != EOF && c != '\n')
		++len;
	/* учитываем в длине строки и сам символ '\n' */
	if (c == '\n')
		++len;
	return len;
}
	
		