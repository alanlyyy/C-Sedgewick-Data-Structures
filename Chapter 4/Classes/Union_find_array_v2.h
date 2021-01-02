#pragma once
#include <iostream>
class UF
{
private:
	int** id; //arrays id stores the root element in id[i][0]
			//sz stores number of elements connected to the root element in id[i][1]

	int size_of_array;

	int find(int x) {

		//traverse to next node until root element is found
		while (x != id[x][0]) {
			x = id[x][0];
		}
		return x;
	}

	int find_compression(int x) {
		//for each iteration traverse 2 nodes until we get to the root node.

		//traverse to next node until root element is found
		while (x != id[x][0]) {
			id[x][0] = id[id[x][0]][0];
			x = id[x][0];
		}
		return x;
	}
public:
	UF(int N) {
		id = new int*[N];
		size_of_array = N;

		for (int i = 0; i < N; i++) {
			id[i] = new int[2];
			
			//set each root node to itself
			id[i][0] = i;

			//set the size of each node to 1
			id[i][1] = 1;
			}
		}



	int find(int p, int q) {
		return (find(p) == find(q));
	}

	int find_compression(int p, int q) {
		return (find_compression(p) == find_compression(q));
	}

	void  unite(int p, int q) {

		//find root node of p and find root node of q
		int i = find(p), j = find(q);

		if (i == j) {
			return;
		}

		if (id[i][1] < id[j][1]) {
			id[i][1] = j;
			id[j][1] += id[i][1];
		}
		else {
			id[j][1] = i;
			id[i][1] += id[j][1];
		}
	}

	void  unite_compression(int p, int q) {

		//find root node of p and find root node of q
		int i = find_compression(p), j = find_compression(q);

		if (i == j) {
			return;
		}

		if (id[i][1] < id[j][1]) {
			id[i][1] = j;
			id[j][1] += id[i][1];
		}
		else {
			id[j][1] = i;
			id[i][1] += id[j][1];
		}
	}

	int return_num_nodes(int index) {
		//return number of nodes connected to given root node
		int count = 0;

		//traverse map, count all nodes with the root node equal to index
		for (int i = 0; i < size_of_array; i++) {

			//if the root of current node is index
			if (id[i][0] == index) {
				count += 1;
			}
		}
		return count;
	}

	void print_paths() {

		for (int i = 0; i < size_of_array; i++) {
			std::cout << "index: " << i << " root: " << id[i][0] << " Weight: " << id[i][1] << std::endl;
		}
	}
};