#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define NUMLEN 7

int c_occur(int c);
int neighbour(int c);

char number_str[NUMLEN];

int main() {

	unsigned long int n = 1112233;
	unsigned int n_numbers = 0;

	while (n < 3322111) {

		sprintf(number_str, "%lld", n);
		if (c_occur('1') == 3 && c_occur('2') == 2 && c_occur('3') == 2 && neighbour('1') == 0)
			++n_numbers;
		n++;
	}

	printf("%d\n", n_numbers);

	printf("%d\n", clock() / CLOCKS_PER_SEC);

	Sleep(999999999);

	return 0;
}

int c_occur(int c) {

	int n_occur = 0;

	for (int i = 0; i < NUMLEN; i++) {
		if (c == number_str[i])
			++n_occur;
	}

	return n_occur;
}

int neighbour(int c) {

	int result = 0;

	for (int i = 0; i < (NUMLEN - 1); i++){

		if (number_str[i] == c && number_str[i + 1] == c) {
			result = -1;
			break;
		}
		else
			result = 0;
	}

	return result;
}
