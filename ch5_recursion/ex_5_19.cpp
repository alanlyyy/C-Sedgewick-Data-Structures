#include <iostream>

int rule(int low, int high, int depth,int index) {

	int m = (low + high) / 2;

	if (depth > 0) {

		//if index is found in upper half
		if (index  > m) {
			return rule(m, high, depth - 1, index);
		}
		//if index is found return the depth
		else if (m == index) {
			return depth;
		}
		//if m is found in lower half
		else {
			return rule(low, m,  depth - 1, index);
		}
	}
	else {
		return 0;
	}
}

int main_5_19() {
	for (int i = 0; i < 7;i++)
		std::cout << rule(0, 7, 3,i) << std::endl;
	return 0;
}