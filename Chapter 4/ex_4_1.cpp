#include "Point.h"

int count_pair_of_points_within_d(int d, int num_points) {
	//calculate distance between pair of points using distance function found within the class.
	int i, cnt = 0;

	//create a Point array of size num_points
	Point* a = new Point[num_points];

	for (i = 0; i < num_points; i++) {

		for (int j = i + 1; j < num_points; j++) {
			
			//if curr point distance with next point is within d, update the count.
			if (a[i].distance(a[j]) < d) {
				cnt++;
			}
		}
	}

	std::cout << cnt << " pairs within " << d << std::endl;

	return cnt;
}

int count_pair_of_points_within_d_v2(int d, int num_points) {
	//count pairs of points within d using "friend" distance function outside of class
	int i, cnt = 0;

	//create a Point array of size num_points
	Point* a = new Point[num_points];

	for (i = 0; i < num_points; i++) {

		for (int j = i + 1; j < num_points; j++) {

			//if curr point distance with next point is within d, update the count.
			if (distance(a[i],a[j]) < d) {
				cnt++;
			}
		}
	}

	std::cout << cnt << " pairs within " << d << std::endl;

	return cnt;
}
int main_4_1() {

	count_pair_of_points_within_d(1, 17);
	count_pair_of_points_within_d_v2(1, 17);
	return 0;
}