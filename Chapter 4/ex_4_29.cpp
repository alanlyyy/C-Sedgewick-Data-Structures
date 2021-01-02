#include "union_find.h"
#include <iostream>
#include<time.h>

int* fill_array(int* arr, int size) {

	//initialize random seed
	//srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % size;
	}

	return arr;
}
void test_union_find() {
	int num_links = 10;
	int * p = new int[num_links];
	int* q= new int[num_links];

	//p = fill_array(p, num_links);
	//q = fill_array(q, num_links);

	p[0] = 0;
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;
	p[4] = 9;
	p[5] = 6;
	p[6] = 6;
	p[7] = 6;
	p[8] = 0;
	p[9] = 0;
	q[0] = 7;
	q[1] = 1;
	q[2] = 2;
	q[3] = 8;
	q[4] = 1;
	q[5] = 9;
	q[6] = 1;
	q[7] = 5;
	q[8] = 3;
	q[9] = 8;


	UF info(num_links);

	for (int i = 0; i < num_links ; i++) {

		//if the root elements of current element p and element q are not equal
		if (!info.find(p[i], q[i])) {

			//get the root with the largest node, and combine the smaller group with the larger group, pointing to new largest node.
			info.unite(p[i], q[i]);

			std::cout << " " << p[i] << " " << q[i] << std::endl;
			info.print_paths();
		}
	}

	//return number of nodes under sub root node 4
	std::cout << info.return_num_nodes(4) << std::endl;
	
}

void test_union_find_path_compression() {
	int num_links = 10;
	int* p = new int[num_links];
	int* q = new int[num_links];

	//p = fill_array(p, num_links);
	//q = fill_array(q, num_links);

	p[0] = 0;
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;
	p[4] = 9;
	p[5] = 6;
	p[6] = 6;
	p[7] = 6;
	p[8] = 0;
	p[9] = 0;
	q[0] = 7;
	q[1] = 1;
	q[2] = 2;
	q[3] = 8;
	q[4] = 1;
	q[5] = 9;
	q[6] = 1;
	q[7] = 5;
	q[8] = 3;
	q[9] = 8;

	UF info(num_links);

	for (int i = 0; i < num_links; i++) {

		//if the root elements of current element p and element q are not equal
		if (!info.find_compression(p[i], q[i])) {

			//get the root with the largest node, and combine the smaller group with the larger group, pointing to new largest node.
			info.unite_compression(p[i], q[i]);

			std::cout << " " << p[i] << " " << q[i] << std::endl;
			info.print_paths();
		}
	}

	std::cout << info.return_num_nodes(4) << std::endl;


	
}

int main_4_29() {
	test_union_find();
	std::cout <<"------------------------"<< std::endl;
	test_union_find_path_compression();
	return 0;
}