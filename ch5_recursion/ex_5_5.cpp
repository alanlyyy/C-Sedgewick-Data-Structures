#include <iostream>
#include "C:\Users\Alan\source\repos\Cpp_sedgewick\ch4_ADT\Stack_linked_list.h"

int gcd_2(int m, int n) {
	//computer gcd between m and n using a stack.
	STACK_ll<int> val;

	val.push(m);
	val.push(n);

	int big = m;
	int small = n;

	while (small != 0) {


		small = val.pop();
		big = val.pop();

		int temp1 = small;
		int temp2 = big;

		big = temp1;
		small = temp2 % temp1;

		val.push(big);
		val.push(small);

		std::cout << big << " " << small << std::endl;
	}

	return big;
};

int main20() {
	std::cout << gcd_2(314159, 271828) << std::endl;

	return 0;
};