#include "random_queue.h"

struct link {
	
	int id;
	int weight;

	link(int i=0, int w=0) {
		id = i;
		weight = w;
	}
};

struct pairs {
	int i;
	int j;

	pairs(int i2=0,int j2=0) {
		i = i2;
		j = j2;
	}
};

void connectivity(int N, pairs * pair_array) {
	int i, j, k;
	//create a link array of N elements
	link* link_connect = new link[N]();

	random_queue_array<pairs> qa(N);

	//initialize all links with weight of 1
	//insert all pairs into the queue
	for (i = 0; i < N; i++) {
		qa.put_in_back(*(pair_array+i));
		link_connect[i] = link(i, 1);
	}
	//loop through N number of pairs
	for (k = 0; k < N; k++) {
		pairs item = qa.get_random();
		int num1 = item.i;
		int num2 = item.j;

		for (i = num1; i != link_connect[i].id; i = link_connect[i].id);
		for (j = num2; j != link_connect[j].id; j = link_connect[j].id);

		if (i == j) {
			continue;
		}

		if (link_connect[i].weight < link_connect[j].weight) {
			link_connect[i].id = j;
			link_connect[j].weight += link_connect[i].weight;
			std::cout << "weight: "<< link_connect[j].weight << " id: " << link_connect[j].id << std::endl;
		}
		else {
			link_connect[j].id = i;
			link_connect[i].weight += link_connect[j].weight;
			std::cout << "weight: " << link_connect[i].weight << " id: " << link_connect[i].id << std::endl;
		}

		std::cout << num1 << " " << num2 << std::endl;
	}
}

int main_ex_4_52() {
	int N = 5;
	pairs* pair_array = new pairs[N]();

	pair_array[0] = pairs(0, 2);
	pair_array[1] = pairs(0, 3);
	pair_array[2] = pairs(1, 2);
	pair_array[3] = pairs(3, 3);
	pair_array[4] = pairs(4, 1);

	connectivity(N, pair_array);

	return 0;
}