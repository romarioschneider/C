#include <stdio.h>
#define MAXLEN 1000
#define TRESHOLD 80 /* порог для длины строки, которая будед выводиться на печать в терминал */

int getlen(char line[]);

int main() {
	
	int len = 0;
	char line[MAXLEN];
	
/* пока вход строка не пустая проверяем ее длину, если она болше, чем TRESHOLD - печатаем в вывод */
	while((len = getlen(line)) != 0) {
		if (len > TRESHOLD)
			printf("%s\n", line);
	}
	return 0;
}


/* функция подсчета длины строки и записи входящей строки в массив */
int getlen(char c_array[]) {
	int c, len = 0;
	/* увеличиваем счетчик символов в строке пока не встретится символ новой строки и записываем символы в массив */
	while((c = getchar()) != EOF && c != '\n') {
		c_array[len] = c;
		++len;
	}
	/* учитываем в длине строки и сам символ '\n' */
	if (c == '\n') {
		++len;
	}

	return len;
}