#include <stdio.h>

main () {
	int c = 0;
	int checkc = 'a';
	while ((c = getchar()) != EOF) {
		if (c != ' ' ) {
			putchar(c);
			checkc = c;
		}
		if (c == ' ' && checkc != ' ') {
			putchar(c);
			checkc = ' ';
		}
	}
}