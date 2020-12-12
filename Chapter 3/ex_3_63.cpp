#include <iostream>
#include <stdlib.h>
#include <string>

int compare(const void* i, const void* j) {
	return strcmp(*(char**)i, *(char**)j);
}

void array_sort_before() {

	const int Nmax = 100;
	const int Mmax = 100;


	char* a[Nmax];  //a will be a pointer to buf
	char buf[Mmax];	//create an char array of size Mmax, elements are populated from cin

	int N;
	int M = 0;

	for (N = 0; N < Nmax; N++) {

		//a points to the first element in buf with a length of M
		a[N] = &buf[M];

		//if a[n] doesn't read anything break out of loop
		if (!(std::cin >> a[N])) {
			break;
		}

		//update M with the next position
		M = strlen(a[N]) + 1;
	}

	//sort the strings
	qsort(a, N, sizeof(char*), compare);

	//N equals Nmax at this point, print entire string.
	for (int i = 0; i < N; i++) {
		std::cout << a[i] << std::endl;
	}
	
}

void array_sort_after(char** char_array, char * mystring,int N) {
	//append mystring size 100 into char_array. Performing a sort, and printing out the elements
	//N = current number of elements in char_array

	char** a = char_array;  //array of size 100
	char *buf = mystring;	//string

	//allocate memory for mystring with size 100
	a[N] = new char[100];

	//a points to the first element in buf with a length of M
	a[N] = mystring;

	//sort the strings
	qsort(a, N+1, sizeof(char*), compare);

	//N equals total initialized elements at this point, print sorted strings
	for (int i = 0; i < N+1; i++) {
		std::cout << a[i] << std::endl;
	}
}

int main_3_63() {
	int size = 10;
	char** char_arr = new char* [size];
	char s1[] = "alphabet\0";
	char s2[] = "delbet\0";
	char s3[] = "binary\0";
	char s4[] = "crazy\0";
	char s5[] = "albinorazy\0";

	array_sort_after(char_arr, s1,0);
	std::cout << "==================="<<std::endl;
	array_sort_after(char_arr, s2,1);
	std::cout << "===================" << std::endl;
	array_sort_after(char_arr, s3,2);
	std::cout << "===================" << std::endl;
	array_sort_after(char_arr, s4, 3);
	std::cout << "===================" << std::endl;
	array_sort_after(char_arr, s5, 4);
	std::cout << "===================" << std::endl;
	return 0;
}