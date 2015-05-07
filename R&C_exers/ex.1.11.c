#include <stdio.h>

#define IN  1
#define OUT 0

/* если во входном потоке 1 строка, но не заканчиваетс€ символом '\n' - программа всеравно выдаст к-во строк = 1, стандартна€ wc выводит 0 */
/* неверные резульаты можно получить путем пропускани€ исх. текста данной программы —  ќћћ≈Ќ“ј–»яћ» через утилиту. wc и эта программа дадут разные результаты */

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