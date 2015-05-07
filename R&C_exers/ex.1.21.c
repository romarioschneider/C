#include <stdio.h>
#define TABLEN 8
#define MAXLEN 1000

int getlen();
int entab(int s);
int space_c(int i);

char line[MAXLEN];

int main() {
	
	int len, i;
	
	/* пока вход§ща§ строка не пуста§ ... */
	while((len = getlen()) != 0) {
		/* если строка состоит из одних пробелов - вызываем entab */
		if (len == space_c(len))
			len = entab(len);
		/* посимвольно выводим на печать строку дл€ предотвращени€ выведени§ символов предыдущей строки, если она была длиннее текущей */
		i = 0;
		while (i < len) {
			printf("%c", line[i]);
			++i;
		}
	printf("\n");
	}
	
	return 0;
}

/* функциІ подсчета длины строки и записи входІщей строки в массив */
int getlen() {

	int c, len = 0;
	
	/* увеличиваем счетчик символов в строке пока не встретитс€ символ новой строки и записываем символы в массив */
	while((c = getchar()) != EOF && c != '\n') {
			line[len] = c;
			++len;
	}
	
	return len;
}

/* функци€ замены символов табул€ции количеством = TABLEN символами пробелов */
int entab (int s) {
	
	/* вычисл€ем к-во табов, отбрасыва€ остаток */
	int count_tab = s / TABLEN;
	int i = 0;
	/* если остаток от делени€ ненулевой - значит были еще пробелы до последней позиции табул€ции и надо добавить еще один таб */
	if (s % TABLEN != 0)
		++count_tab;
	
	while (i < count_tab) {
		line[i] = '\t';
		++i;
	}
	
	return count_tab;
}

/* ф-€ подсчета количества пробелов в строке */
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
