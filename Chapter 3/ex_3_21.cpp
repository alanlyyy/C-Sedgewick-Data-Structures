#include <iostream>
#include <time.h>
#include "Triangle_Point.h"


float randFloat() {
	return 1.0 * rand() / RAND_MAX;
}

void find_closest_point(int num_pts) {
	int i;

	//shortest is set to 1, because longest length in unit square is 1
	float shortest_distance = 1;
	Point p1, p2;

	int N = num_pts;

	//create an array of point elements
	Point* a = new Point[N];

	for (i = 0; i < N; i++) {
		a[i].x = randFloat();
		a[i].y = randFloat();
	}

	for (i = 0; i < N; i++) {

		for (int j = i + 1; j < N; j++) {

			//if the distance between 2 points is the shortest, save new shortest distance
			Distance_suite ds = Distance_suite();

			float d = ds.distance(a[i], a[j]);
			
			if ( d < shortest_distance) {
				shortest_distance = d;
				p1 = a[i];
				p2 = a[j];
			}
		}
	}

	std::cout << "Shortest distance =" << shortest_distance << "   P1 -- (" << p1.x << "," << p1.y << ")" << "   P2 -- (" << p2.x << "," << p2.y << ")";
	std::cout << std::endl;
}

int main_3_21() {
	/* initialize random seed: */
	//so we get generate random numbers using rand() during every compilation.
	srand(time(NULL));
	find_closest_point(10);
	return 0;
}