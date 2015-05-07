#include <stdio.h>

float cels (float);

int main() {
	float fahr = 0;
	int upper = 300;
	int step = 20;
	printf("Fahr     Cels\n");
	while (fahr <= upper) {
		printf("%4.0f  %7.3f\n", fahr, cels(fahr));
		fahr = fahr + step;
	}
	return 0;
}
	
float cels (float value) {
	return (5.0/9.0) * (value-32.0);
}
