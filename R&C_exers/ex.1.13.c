#include <stdio.h>

#define NO  0 /* вне слова */
#define YES 1 /* вслове */
#define MAXWORD 20 /* условно рассматриваем 20 разных длин слова - как следствие, MAXWORD элементов диаграммы */

main () {
	int c, i, ii, in_word;
	int array_len[MAXWORD];
	int word_len = 0;
	in_word = NO; /* переменная-флаг для обхода слов нулевой длины */
	
	for (i = 0; i <= MAXWORD; ++i)
		array_len[i] = 0;
	
	while ((c = getchar()) != EOF) {
		/* если символ печатаемый-видимый - мы в слове и можно подсчитывать его длину */
		if (c != ' ' && c != '\t' && c != '\n') {
			in_word = YES;
			word_len++;
		}
		/* иначе после 1-го выхода из слова фиксируем его длину и устанавливаем флаг, что мы не в слове на случай продолжения последовательности пробелов, etc... */
		else if (in_word == YES) {
			in_word = NO;
			array_len[word_len]++;
			word_len = 0;
		}
	}
	/* горизонтальная гистограмма */
	for (i = 1; i <= MAXWORD; ++i) {
		printf("len=%2d:  %d", i, array_len[i]);
		for (ii = 0; ii < array_len[i]; ++ii)
			printf("#");
		printf("\n");
	}
	
	/* вертикальная гистограмма */
	for (i = 1; i <= MAXWORD; ++i)
		printf("len=%2d ", i);
		
	printf("\n");
		
	for (i = 1; i <= MAXWORD; ++i)
		printf("%6d ", array_len[i]);
		
	printf("\n");
		
	for (i = 1; i <= MAXWORD; ++i) {
		for (ii = 1; ii <= MAXWORD; ++ii) {
			if (array_len[ii] >= i) 
				printf("%7s", "#");
			else
				printf("%7s", " ");
		}
		printf("\n");
	}
}