#include <math.h>
#include <stdio.h>

int main() {
	START:
	printf("Press one to find the primes < 10^6, press two to find the primes \u2264 7^t such that t = {t \u2208 \u2124 | 2 \u2264 t \u2264 7}, or press zero to quit : ");
	int answer = 0;
	scanf("%i", &answer);
	if (answer == 1) {
		printf("\nCalculate the prime numbers p such that p = {p \u2208 \u2124 | 0 \u2264 p \u2264 10^6 and p is only divisible by one and itself}.\n");
		int J = pow(10, 6);
		int count = J-2;
		int *P = malloc(J*sizeof(int));
		P[0] = 0; 
		int i = 1;
		for (; i < J; i++) P[i] = 1;
		int p = 2;
		i = 0;
		while (p <= (int)sqrt((double)J)) {
			i = p + p;
			while (i <= J) {
				if (P[i] == 1) {
					P[i] = 0;
					count--;
				}
				i += p;
			}
			i = p + 1;
			while (i <= (int)sqrt((double)J) && P[i] == 0) i++;
			p = i;
		}
		int j = 2;
		int five = 1;
		int last = count - 5;
		int count2 = 0;
		int flag = 0;
		for (; j < J; j++) {
			if (P[j] == 1) {
				if (!count2) printf("\nThe first 5 primes are: \n");
				if (five < 6) { printf("%i : %i\n", five, j); five++;}
				else if (last == count2) { 
					if (!flag) { printf("\nThe last 5 primes are: \n"); flag++;}
					printf("%i : %i\n", last+1, j); 
					last++;
				} count2++;
			}
		}
		int approx = (int)(J/log(J));
		printf("\nThe total number of primes up to 10^6 is: %i", count);
		printf("\nThe approximate number of primes is: \u03C0(10^6) = 10^6/ln(10^6) = %i\n\n", approx);
		free(P);
		goto START;
	} else if (answer == 2) {
		int t = 2;
		printf("\nThe number of primes up to and including 7^t such that t = {t \u2208 \u2124 | 2 \u2264 t \u2264 7}:\n\n");
		while (t != 8) {
			int J = pow(7, t);
			int pi = J / log(J);
			int count = 0;
			int *P = malloc(J*sizeof(int));
			P[0] = 0;
			int i = 1;
			for (; i < J; i++) P[i] = 1;
			int p = 2;
			i = 0;
			while (p <= (int)sqrt((double)J)) {
				i = p + p;
				while (i <= J) {
					P[i] = 0;
					i += p;
				}
				i = p + 1;
				while (i <= (int)sqrt((double)J) && P[i] == 0) i++;
				p = i;
			}
			int j = 1;
			for (; j < J; j++) {
				if (P[j] == 1) count++;
			}
			printf("t = %i : %i\t\u03C0(7^%i) = 7^%i/ln(7^%i) = %i\n", t, count-1, t, t, t, pi);
			t++;
			free(P);
		} printf("\n"); goto START;
	} else if (!answer) {
		printf("\nThank you!\nBYE\n");
	} else goto START;
}









