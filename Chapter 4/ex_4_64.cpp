#include <iostream>
#include "Equivalence_Relation_First_Class_ADT.h"

struct pairs {
	int i = 0;
	int j = 0;

	pairs(int i2, int j2) {
		i = i2;
		j = j2;
	}

};

int find(UF_first_class_Vertex** arr, int x) {
	while (x != (**(arr + x)).ID()) {
		x = (**(arr +x)).ID();
	}
	return x;
}
int find(UF_first_class_Vertex** arr, int p, int q) {
	return find(arr, p) == find(arr, q);
}

void unite(UF_first_class_Vertex** arr, int p, int q) {
	int i = find(arr,p);
	int j = find(arr,q);

	if (i == j) {
		return;
	}

	if ((**(arr + i)).SZ() < (**(arr + j)).SZ()) {
		(**(arr + i)).set_ID(j);
		(**(arr + j)) += (**(arr + i));
	}
	else {
		(**(arr + j)).set_ID(i);
		(**(arr + i)) += (**(arr + j));
	}
}

int test_464b() {
	int N = 10;

	//array of 30 vertices (0,1,2......,29)
	UF_first_class_Vertex** vertex_relations = new UF_first_class_Vertex* [N];

	//initialize N vertices in array
	for (int i = 0; i < N; i++) {
		*(vertex_relations + i) = new UF_first_class_Vertex();

		(**(vertex_relations+i)).set_ID(i);
		(**(vertex_relations + i)).set_SZ(1);
		(**(vertex_relations + i)).set_max_size(N);
	}

	//2. insert pairs
	pairs f0 = pairs(1, 2);
	pairs f1 = pairs(1, 3);
	pairs f2 = pairs(1, 4);
	pairs f3 = pairs(1, 5);
	pairs f4 = pairs(2, 4);
	pairs f5 = pairs(3, 5);

	unite(vertex_relations, f0.i, f0.j);
	unite(vertex_relations, f1.i, f1.j);
	unite(vertex_relations, f2.i, f2.j);
	unite(vertex_relations, f3.i, f3.j);
	unite(vertex_relations, f4.i, f4.j);
	unite(vertex_relations, f5.i, f5.j);

	for (int i = 0; i < N; i++) {
		std::cout << *(vertex_relations + i) << std::endl;
	}

	delete vertex_relations;

	return 0;
}

int main_6_46() {
	test_464b();
	return 0;
}