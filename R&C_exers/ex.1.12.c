#include <stdio.h>

#define NO  0
#define YES 1

main () {
	int c, in_word;
	in_word = NO;
	while ((c = getchar()) != EOF) {
		if ((c == ' ' || c == '\t' || c == '\n') && in_word == YES) {
			in_word = NO;
			putchar('\n');
		}
		else if ((c == ' ' || c == '\t' || c == '\n') && in_word == NO)
			;
		else {
			in_word = YES;
			putchar(c);
		}
	}
}