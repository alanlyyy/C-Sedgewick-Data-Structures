#include <iostream>

struct Item {
	int size;
	int val;

	Item(int s=0, int v=0) {
		size = s;
		val = v;
	}
};

static int N = 5;
static Item* items = new Item[N];
static int* maxKnown;
static Item* itemKnown;

int knap(int v, int M) {

	if (v == M) {
		maxKnown = new int[M+1]();
		itemKnown = new Item[M+1];
	}

	int j, space, max, maxi = 0, t;

	if (maxKnown[v] != 0) {
		return maxKnown[v];
	}

	for (j = 0, max =0; j < N; j++) {

		if ((space = (v - items[j].size)) >= 0) {

			if ((t = (knap(space,M) + items[j].val)) > max) {
				max = t;
				maxi = j;
			}

		}
	}
	maxKnown[v] = max;
	itemKnown[v] = items[maxi];

	return max;
}
int main_5_48() {
	//initialize Items array 
	int size[] = { 3,4,7,8,9 };
	int val[] = { 4,5,10,11,13 };

	Item i1, i2, i3, i4, i5;
	items[0] = i1;
	items[1] = i2;
	items[2] = i3;
	items[3] = i4;
	items[4] = i5;

	for (int i = 0; i < 5; i++) {
		items[i].size = size[i];
		items[i].val = val[i];
	}

	std::cout << knap(17,17) << std::endl;

	for (int j = 0; j < 18; j++) {
		std::cout << maxKnown[j] <<" "<< itemKnown[j].size <<" " <<itemKnown[j].val << std::endl;
	}
	return 0;
}