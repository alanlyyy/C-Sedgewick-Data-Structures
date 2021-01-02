#pragma once
#include <iostream>
class UF
{
private:
	int* id, *sz; //arrays id stores the root element, sz stores number of elements connected to the root element
	int size_of_array;

	int find(int x) {

		//traverse to next node until root element is found
		while (x != id[x]) {
			x = id[x];
		}
		return x;
	}

	int find_compression(int x) {
		//for each iteration traverse 2 nodes until we get to the root node.

		//traverse to next node until root element is found
		while (x != id[x]) {
			id[x] = id[id[x]];
			x = id[x];
		}
		return x;
	}
public:
	UF(int N) {
		id = new int[N];
		sz = new int[N];
		size_of_array = N;
		for (int i = 0; i < N; i++) {
			id[i] = i;
			sz[i] = 1;
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

		if (sz[i] < sz[j]) {
			id[i] = j;
			sz[j] += sz[i];
		}
		else {
			id[j] = i;
			sz[i] += sz[j];
		}
	}

	void  unite_compression(int p, int q) {

		//find root node of p and find root node of q
		int i = find_compression(p), j = find_compression(q);

		if (i == j) {
			return;
		}

		if (sz[i] < sz[j]) {
			id[i] = j;
			sz[j] += sz[i];
		}
		else {
			id[j] = i;
			sz[i] += sz[j];
		}
	}

	int return_num_nodes(int index) {
		//return number of nodes connected to given root node
		int count = 0;

		//traverse map, count all nodes with the root node equal to index
		for (int i = 0; i < size_of_array; i++) {

			//if the root of current node is index
			if (id[i] == index) {
				count += 1;
			}
		}
		return count;
	}

	void print_paths() {

		for (int i = 0; i < size_of_array; i++) {
			std::cout << "index: "<< i<< " root: " << id[i] << " Weight: " << sz[i] << std::endl;
		}
	}
};