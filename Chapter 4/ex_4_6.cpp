#include <iostream>
#include <cmath>

class Item {
	//item object used to store a floating point number
public:
	friend int operator==(Item ,Item );
	float val = 0;
};

int operator==(Item a, Item b) {
	//overload == operator to compare between 2 item objects
	float abs_a = sqrt(a.val * a.val);
	float abs_b = sqrt(b.val * b.val);
	if (abs_a > abs_b) {
		return( ((abs_a - abs_b) / abs_a) < 0.000006);
	}
	else {
		return(((abs_b - abs_a) / abs_b) < 0.000006);
	}
}

int main_4_6() {
	Item a;
	a.val = 6;
	Item b;
	b.val = 5.99036;

	Item c;
	c.val = 6;
	Item d;
	d.val = 5.999996;

	std::cout << (a == b) << std::endl;
	std::cout << (c == d) << std::endl;
	return 0;
}