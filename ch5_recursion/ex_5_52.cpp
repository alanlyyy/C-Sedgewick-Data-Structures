#include <iostream>

struct Item2 {
	int size;
	int val;

	Item2(int s = 0, int v = 0) {
		size = s;
		val = v;
	}
};

static int N = 5;
Item2* items2 = new Item2[N];
int* maxKnown2;
Item2* itemKnown2;
static int* items_count;

int knap_space(int v, int M, Item2 it) {
	//overload knap function to include Item object,
	//count the number of times item is found in the optimal solution.

	if (v == M) {
		maxKnown2 = new int[M + 1]();
		itemKnown2 = new Item2[M + 1];
	}

	int j, space, max, maxi = 0, t;

	if (maxKnown2[v] != 0) {
		return maxKnown2[v];
	}

	for (j = 0, max = 0; j < N; j++) {

		if ((space = (v - items2[j].size)) >= 0) {

			t = (knap_space(space, M, it) + items2[j].val);
			if (t > max) {

				max = t;
				maxi = j;
			}

		}
	}
	maxKnown2[v] = max;
	itemKnown2[v] = items2[maxi];


	//if max is larger than absolute max, and absolute max != 0
	if ((maxKnown2[v] >= maxKnown2[M]) && maxKnown2[M] != 0)
	{
		//starting at a full bag.
		int cap = M;

		while (cap > 0) {

			//print contents of optimal solution for array
			if (itemKnown2[cap].val == it.val) {
				std::cout << "1 : " <<maxKnown2[v] << " "<< itemKnown2[cap].val << " " <<  itemKnown2[cap].size << std::endl;
			}
			else {
				std::cout << "0 : " << maxKnown2[v] << " " << itemKnown2[cap].val << " " << itemKnown2[cap].size << std::endl;
			}

			//decrement capacity
			cap = cap - itemKnown2[cap].size;
		}

	}

	return max;
}

int main_5_52() {
	//initialize Items array 
	int size[] = { 3,4,7,8,9 };
	int val[] = { 4,5,10,11,13 };

	Item2 i1, i2, i3, i4, i5;
	items2[0] = i1;
	items2[1] = i2;
	items2[2] = i3;
	items2[3] = i4;
	items2[4] = i5;

	for (int i = 0; i < 5; i++) {
		items2[i].size = size[i];
		items2[i].val = val[i];
	}

	std::cout << knap_space(17, 17, items2[2]) << std::endl;

	std::cout << " --------------" << std::endl;
	//for (int i = 0; i <= 17; i++)
	//	std::cout << itemKnown2[i].val << " "<< itemKnown2[i].size << " " << maxKnown2[i] << std::endl;
	return 0;
}