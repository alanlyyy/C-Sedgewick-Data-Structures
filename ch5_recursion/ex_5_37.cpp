#include <iostream>

int maxN = 1000;
static int knownF[1000];

int F(int i)
{
	if (knownF[i] != 0) {
		return knownF[i];
	}

	int t = i;

	if (i < 0) {
		return 0;
	}

	if (i > 1) {
		return F(i - 1) + F(i - 2);
	}

	return knownF[i] = t;
}

long long get_pisano_period(long long m) {
	long long a = 0, b = 1, c = a + b;

	for (int i = 0; i < m * m; i++) {
		c = (a + b) % m;
		a = b;
		b = c;
		
		if (a == 0 && b == 1) {
			return i + 1;
		}
	}
}

long long get_fibonacci_huge(long long n, long long m) {

	//F(n) % m = F(remainder) % m = 1
	//valid for F( i >= 2 );


	long long remainder = n % get_pisano_period(m);


	//accounts for first cycle when i = 0
	long long first = 0;
	long long second = 1;
	long long res = remainder;

	//compute F(remainder) % m, shorter version of F(n) % m
	for (int i = 1; i < remainder; i++) {
		res = (first + second) % m;
		first = second;
		second = res;
	}

	//return the last last value calculated in the loop % m, as final answer for F(n) % m;
	return res % m;
}

int main_5_37() {
	//std::cout << (F(1000)%7) << std::endl;

	std::cout << get_fibonacci_huge(1000, 7) << std::endl;
	return 0;
}

