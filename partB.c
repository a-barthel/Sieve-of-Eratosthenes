#include <stdio.h>
#include <math.h>

int main() {
	printf("\nCalculate the prime numbers p such that p = {p \u2208 \u2124 | 2*10^8 \u2264 p \u2264 2*10^8+10^6 and p is only divisible by one and itself}.\n");
	int I = 2 * pow(10, 8);
	int J = 2 * pow(10, 8) + pow(10, 6);
	int L = (int)sqrt((double)J);
	// Copy and Paste Part A
	int sqrtJ = L;
	int count = pow(10, 6)-2;
	int *P = malloc(sqrtJ*sizeof(int));
	P[0] = 0;
	int i = 1;
	for (; i < sqrtJ; i++) P[i] = 1;
	int p = 2;
	while (p <= (int)sqrt((double)sqrtJ)) {
		i = p + p;
		while (i <= sqrtJ) {
			P[i] = 0;
			i += p;
		}
		i = p + 1;
		while (i <= (int)sqrt((double)sqrtJ) && P[i] == 0) i++;
		p = i;
	}
	// We have 0<j<L, j is prime iff P[j] = 1.
	int *A = malloc(1000000*sizeof(int));
	A[0] = 0;
	i = 1;
	for (; i < 1000000; i++) A[i] = 1; 
	p = 2;
	for (; p <= L; p++) {
		if (P[p] == 0) continue;
		int fl = (int)floor(I/p);
		i = (fl+1) * p;
		while (i <= J) {
			if (A[i-I] == 1) {
				count--;
				A[i-I] = 0;
			}
			i += p;
		}
	}
	int five = 1;
	int last = count - 4;
	int flag = 0;
	int count2 = 0;
	int pi = (J/log(J))-(I/log(I));
	for (i = 0; i <= pow(10, 6); i++) {
		if (A[i] == 1) {
			if (!count2) printf("\nThe first 5 primes are: \n");
			if (five < 6) { printf("%i : %i\n", five, i+I); five++;}
			else if (last == count2) { 
				if (!flag) { printf("\nThe last 5 primes are: \n"); flag++;}
				printf("%i : %i\n", last, i+I); 
				last++;
			} count2++;
		}
	}
	printf("\nThe total number of primes between 2*10^8 and 2*10^8+10^6 is : %i\n", count);
	printf("The approximate number of primes between 2*10^8 and 2*10^8+10^6 is : \u03C0(J) - \u03C0(I) = (J/lnJ) - (I/lnI) = %i\n\n", pi);
	free(P); free(A);
}





