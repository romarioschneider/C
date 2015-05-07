#include <stdio.h>
#define MAXLEN 1000

int getlen(char line[]);
void reverse(char line[], int line_lenght);

int main() {
	
	int len, i;
	char line[MAXLEN];
	
	/* пока вход€ща€ строка не пуста€ ... */
	while((len = getlen(line)) != 0) {
		reverse(line, len);
		i = 0;
		
		/* посимвольно выводим на печать строку дл€ предотвращени€ выведени€ символов предыдущей строки, если она была длиннее текущей */
		while (i < len) {
			printf("%c", line[i]);
			++i;
		}
	printf("\n");
	}
		
	return 0;
}
		
/* функци§ подсчета длины строки и записи вход§щей строки в массив */
int getlen(char c_array[]) {

	int c, len = 0;
	
	/* увеличиваем счетчик символов в строке пока не встретитс§ символ новой строки и записываем символы в массив */
	while((c = getchar()) != EOF && c != '\n') {
		c_array[len] = c;
		++len;
	}
	
	return len;
}

/* ф-ци€ перезаписи строкового аргумента в обратном пор€дке */
void reverse(char c_array[], int array_len) {
	
	/* объ€вл€ем массив дл€ промежуточного хранени€ символов */
	char tmp[MAXLEN];
	int i = 0;
	
	/* копируем символы массива из функции main в массив tmp в обратном пор€дке */
	while (i < array_len) {
		tmp[i] = c_array[array_len - 1 - i];
		++i;
	}
	/* копируем символы из массива tmp обратно в исходный массив */
	i = 0;
	while (i < array_len) {
		c_array[i] = tmp[i];
		++i;
	}
		
}		