/*
Author: Dipankar Dey
Add two number in reverse order
*/

#include <stdio.h>
#include <malloc.h>

static int reverse(int num) {
	int new_num = 0;
	
	while (num >0) {
		new_num *= 10;
		new_num += (num % 10);
		num /= 10;
	}
	
	return new_num;
}

static void append(int *result, int n, int *c) {
	int d = 0;
	while (n > 0) {
		d = (n % 10);
		d += *c;
		n /= 10;
		
		*result *= 10;
		*result += d%10;
		
		*c = d/10;
	}
}

static int add(int n1, int n2) {
	int result = 0;
	int c = 0;
	int d = 0;
	
	n1 = reverse(n1);
	n2 = reverse(n2);
	
	while ((n1 > 0) && (n2 > 0)) {
		d = (n1 % 10) + (n2 % 10);
		d += c;
		n1 /= 10;
		n2/= 10;
		
		result *= 10;
		result += d%10;
		
		c = d/10;
	}
	if (n1 > 0) {
		append(&result, n1, &c);
	} else if (n2 > 0) {
		append(&result, n2, &c);
	}
	if (c > 0) {
		result *= 10;
		result += c%10;
	}
	
	return result;
}
#if 0
int main(int argc, char**argv) {
	int n1;
	int n2;
	
	printf ("Enter first number: ");
	scanf("%d", &n1);
	printf ("Enter second number: ");
	scanf("%d", &n2);
	
	printf ("Result of addition is %d\n", add(n1, n2));
	return 0;
}
#endif

int main(int argc, char**argv) {
	int t;
	int i = 0;
	int **inputs = NULL;
	
	scanf("%d", &t);
	inputs = (int**)malloc(t*sizeof(int*));
	for (i = 0; i<t; i++) {
		inputs[i] = (int*)malloc(2*sizeof(int));
		scanf("%d%d", &(inputs[i][0]), &(inputs[i][1]));
	}
	
	for (i = 0; i<t; i++) {
		printf ("%d\n", add(inputs[i][0], inputs[i][1]));
	}
	
	return 0;
}
