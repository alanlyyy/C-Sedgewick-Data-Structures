//This code implements the functions defined in Trinagle_Point.h
//Point is a structure used in Triangle struct
//Distance_suite has a bunch of functions that test the implementation of Triangle and Point.

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Triangle_Point.h"

float Triangle::get_area() {

	float side1_dx = p1.x - p2.x;
	float side1_dy = p1.y - p2.y;
	float length_AB = sqrt(pow(side1_dx, 2) + pow(side1_dy, 2));

	float side2_dx = p2.x - p3.x;
	float side2_dy = p2.y - p3.y;
	float length_BC = sqrt(pow(side2_dx, 2) + pow(side2_dy, 2));

	float side3_dx = p3.x - p1.x;
	float side3_dy = p3.y - p1.y;
	float length_CA = sqrt(pow(side3_dx, 2) + pow(side3_dy, 2));

	std::cout << length_AB << " " << length_BC << " " << length_CA << std::endl;
		
	//find index of hypotenuse or longest side
	std::vector<float> lengths = { length_AB, length_BC,length_CA };

	//initialize hypotenuse to lengths[0] before finding the max length.
	int max_index = 0;
	float hypotenuse = lengths[max_index];

	for (int index = 1; index < 3; index++) {

		if (lengths[index] > hypotenuse) {

			//store the hypotenuse value if largest length is found
			hypotenuse = lengths[index];
			max_index = index;
		}
	}

	//calculate area, by not using the hypotenuse
	float running_total = 1;
		
	for (int index = 0; index < 3; index++) {
			
		if (index != max_index) {
			running_total *= lengths[index];
		}
	}

	return running_total / 2;
}

//-------------------------------------------------Distance Suite Implementation---------------------------------------------------------

float Distance_suite::distance(Point pair, Point pair2) {
	//calculates pairwise distance for Point object in 1D - 3D
	float dy = (pair2.y - pair.y);
	float dx = (pair2.x - pair.x);
	float dz = (pair2.z - pair.z);

	return sqrt(dx * dx + dy * dy + dz * dz);
}
bool Distance_suite::check_collinear(Point pair1, Point pair2, Point pair3) {
	
	//calculate point distance between points 1 and 2
	float dx1 = pair2.x - pair1.x;
	float dy1 = pair2.y - pair1.y;
	
	//calculate point distance betweens points 2 and 3
	float dx2 = pair3.x - pair2.x;
	float dy2 = pair3.y - pair2.y;

	//calculate the slopes between points 1-2 and points 2-3
	float slope1 = dy1 / dx1;
	float slope2 = dy2 / dx2;

	//if the change in slope is less than 10^-4 return true
	if (abs((slope2 - slope1) < 0.0001)) {
		return 1;
	}
	else {
		return 0;
	}
}

Point Distance_suite::find_shortest_pair(int num_pairs) {

	//stores Point objects
	std::vector<Point> Point_vect;
	float shortest_distance;
	int shortest_index;

	for (int index = 0; index < num_pairs; index++) {

		//create Point object
		Point pair = Point();

		//assign Point index
		pair.index = index;

		//assign Point values
		std::cin >> pair.x >> pair.y;
		std::cout << std::endl;

		//append Point object to vector
		Point_vect.push_back(pair);

		//if element index > 0 or current distance < shortest_distance
		if (index > 0 ){

			//calculate distance with first point
			float curr_distance =  distance(pair,Point_vect[0]);
			std::cout << curr_distance << std::endl;

			//if current distance is smaller than shortest distance record new shortest distance
			if (curr_distance < shortest_distance) {

				shortest_distance = curr_distance;
				shortest_index = pair.index;
			}

		}
		//if current index is 0 
		else {

			//create a new pair marked at 0,0 
			Point pair2 = Point();
			pair2.x = 0;
			pair2.y = 0;
			pair2.index = 0;

			//initialize shortest distance with difference between current_point and 0,0
			shortest_distance = distance(pair2, pair);
			shortest_index = 0;
		}

	}

	return Point_vect[shortest_index];

}

void Distance_suite::calc_area_triangle() {

	//rand() % max_num generates a num between 0 and max_num, we convert to float and then divide by 1000 to conver to decimal.
	Point pair_p1 = Point(float(rand()%1000)/1000, float(rand()%1000)/1000);
	Point pair_p2 = Point(float(rand()%1000)/1000, float(rand()%10000)/1000);
	Point pair_p3 = Point(float(rand()%1000)/1000, float(rand()%1000)/1000);

	Triangle client_triangle = Triangle(pair_p1, pair_p2, pair_p3);
	std::cout << pair_p1.x << " "<<pair_p1.y << std::endl;
	std::cout << pair_p2.x << " " << pair_p2.y << std::endl;
	std::cout << pair_p3.x << " " << pair_p3.y << std::endl;
	std::cout << client_triangle.get_area() << std::endl;
}
void Distance_suite::run_3_7() {
	//wrapper to implement find shortest pair function

	int  num_pair = 5;

	Point myPair = find_shortest_pair(5);
	std::cout << myPair.x << " " << myPair.y << " " << myPair.index;


}

void Distance_suite::run_3_8() {
	//wrapper to test collinear function

	Point pair1 = Point(1, 2, 0);
	Point pair2 = Point(2, 4, 0);
	Point pair3 = Point(3, 6, 0);

	Point pair4 = Point(1, 2, 0);
	Point pair5 = Point(2, 0, 0);
	Point pair6 = Point(3, 9, 0);

	std::cout << " True " << check_collinear(pair1, pair2, pair3) << std::endl;
	std::cout << " False " << check_collinear(pair4, pair5, pair6) << std::endl;
}

void Distance_suite::run_3_9() {
	Point pair1 = Point(0, 0, 0);
	Point pair2 = Point(0.5, 0.5, 0);
	Point pair3 = Point(0.5, 0.0, 0);
	Point pair4 = Point(0, 0, 0);
	Point pair5 = Point(0.5, 0.5, 0);
	Point pair6 = Point(1, 0.0, 0);

	Triangle my_triangle = Triangle(pair1, pair2, pair3);
	Triangle my_triangle2 = Triangle(pair4, pair5, pair6);

	std::cout << my_triangle.get_area() << std::endl;
	std::cout << my_triangle2.get_area() << std::endl;
	
	//generate random triple of pairs with values between 0 and 1
	//print area
	calc_area_triangle();
}


int Distance_suite::main_triagle_point() {

	run_3_7();
	run_3_8();
	run_3_9();
	return 0;
}