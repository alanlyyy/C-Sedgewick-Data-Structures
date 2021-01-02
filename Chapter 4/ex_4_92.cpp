#include <iostream>
#include "set_mod.h"

int main() {

	Set ms(30);
	Set ms2(45);
	int pos_arr[] = { 0,5,6,7,8,13, 15, 21,22,29 };
	int size = sizeof(pos_arr) / sizeof(pos_arr[0]);
	int pos_arr_2[] = { 0,5,6,4,2,11, 15, 21,22,27, 32,39, 41};
	int size2 = sizeof(pos_arr_2) / sizeof(pos_arr_2[0]);


	//test insert multiple positions
	ms.multiple_insert(pos_arr,size);
	ms2.multiple_insert(pos_arr_2,size2);

	Set ms3 = ms;

	Set ms4 = ms2;

	ms.print_set();
	ms2.print_set();
	ms3.print_set();

	std::cout << "copy set" << std::endl;
	//test complement set
	Set t = ms;
	t.print_set();
	std::cout << "complement set" << std::endl;
	t.complement_set();
	t.print_set();


	std::cout << "ms: " << std::endl;
	ms.print_set();

	std::cout << "ms2: " << std::endl;
	ms2.print_set();

	std::cout << "difference_set: " << std::endl;
	Set v = ms.difference_set(ms2);
	v.print_set();

	std::cout << "ms2: " << std::endl;
	ms2.print_set();

	std::cout << "ms3: " << std::endl;
	ms3.print_set();

	std::cout << std::endl;

	std::cout << "intersection_set: " << std::endl;
	Set C = ms2.intersection_set(ms3);
	C.print_set();
	
	std::cout << std::endl;

	std::cout << "ms: " << std::endl;
	ms.print_set();

	std::cout << "ms4: " << std::endl;
	ms4.print_set();

	std::cout << "union_set: " << std::endl;
	Set A = ms4.union_set(ms);
	A.print_set();
	return 0;
}