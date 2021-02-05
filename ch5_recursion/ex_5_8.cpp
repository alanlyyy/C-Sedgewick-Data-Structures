#include <iostream>

char a[] = { "+ * * 12 12 12 144" };
int i = 0;

int eval() {
	int x = 0;

	while (a[i] == ' ') {
		i++;
	}

	if (a[i] == '+') {
		i++;
		std::cout << std::endl;
		int val = eval();
		int val2 = eval();
		int sum_Val = val + val2;

		std::cout << "+ " << val << " " << val2 << " " << sum_Val << std::endl;
		return sum_Val;
	}

	if (a[i] == '*') {
		i++;
		std::cout << std::endl;

		int val = eval();
		int val2 = eval();
		int mult_Val = val * val2;

		std::cout << "* " << val << " " << val2 << " " << mult_Val << std::endl;
		return mult_Val;
	}

	while ((a[i] >= '0') && (a[i] <= '9')) 
	{
		std::cout << a[i];
		x = 10 * x + (a[i++] - '0');
	}

	std::cout << std::endl;

	return x;
}
int main_5_8() {
	std::cout << eval() << std::endl;
	return 0;
}