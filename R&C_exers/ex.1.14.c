#include <stdio.h>
#include <ctype.h>

#define MAXCOUNT 128

main () {

	int c, i, ii;
	int array_count[MAXCOUNT];
	
	for (i = 0; i <= MAXCOUNT; ++i)
		array_count[i] = 0;
	/* инкрементируем значение элемента массива, номер которого совпадает с номеро символа в таблице */
	while ((c = getchar()) != EOF) 
		++array_count[c];
		
	/* горизонтальная гистограмма */
	for (i = 0; i <= MAXCOUNT; ++i) {
		if (array_count[i] != 0) {
			/* если символ печатаемый - выводим его и к-во, иначе - номер символа и ко-во */
			if (isprint(i))
				printf("%3c:  %3d ", i, array_count[i]);
			else
				printf("%3d:  %3d ", i, array_count[i]);
				
			for (ii = 0; ii < array_count[i]; ++ii)
				printf("#");
			printf("\n");
		}
	}
}
