/*
Author: Dipankar Dey
find Next largest number comprising the digits available in array
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX (100)

static void numberToArray(int *arr, int number, int *size) {
	int last = (MAX - 1);
	int i = 0;
	
	if (arr != NULL && size != NULL) {
		*size = 0;
		while (number > 0) {
			arr [last] = number % 10;
			number /= 10;
			last--;
			++*size;
		}
		last++;
		while (i < *size) {
			arr[i] = arr[last];
			i++;
			last++;
		}
	}
}

static int arrayToNumber(int *arr, int size) {
	int i = 0;
	int new_num = 0;
	
	if (arr != NULL) {
		for (i = 0; i < size; i++) {
			new_num *= 10;
			new_num += arr[i];
		}
	}
	return new_num;
}

static int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

static int nextBigNumber (int number) {
	int arr[MAX];
	int size;
	int new_number = -1;
	int found = 0;
	int i;
	
	numberToArray(arr, number, &size);
	if (size <= 0)
		return new_number;
		
	i = (size - 1);
	
	while (i > 0) {
		if (arr[i] > arr[i - 1]) {
			found = 1;
			break;
		}
		i--;
	}
	if (found) {
		int temp = arr[i-1];
		int min = i;
		int j=i;
		for (j = i; j<size; j++) {
			if ((temp < arr[j]) && (arr[j] < arr[min])) {
				min = j;
			}
		}
	    arr[i-1] = arr[min];
		arr[min] = temp;
		int *t_arr = &(arr[i]);
		qsort(t_arr, size - i, sizeof(int), compare);
		
		new_number = arrayToNumber(arr, size);
	}
	
	return new_number;
}

int main(int argc, char**argv) {
	int n;
	printf ("Please enter a number: ");
	scanf("%d", &n);
	
	n = nextBigNumber(n);
	if (n >= 0) {
		printf ("Next big number %d\n", n);
	} else {
		printf ("Not possible\n");
	}
	return 0;	
}