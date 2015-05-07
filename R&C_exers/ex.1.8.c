#include <stdio.h>

main () {
	int n_space, n_tab, n_endline = 0;
	int c;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++n_space;
		if (c == '\t')
			++n_tab;
		if (c == '\n')
			++n_endline;
	}
	printf("n_space = %d, n_tab = %d, n_endline = %d", n_space, n_tab, n_endline);
}