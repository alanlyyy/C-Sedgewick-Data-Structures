#pragma once

//interface for structures, declare objects/classes/structures/functions
struct Point {
	Point() = default;
	Point(float x_param, float y_param, int index_param = 0) : x(x_param), y(y_param), index(index_param) {};

	//overload the Point struct to include a z variable
	Point(float x_param, float y_param, float z_param, int index_param = 0) : x(x_param), y(y_param),z(z_param), index(index_param) {};

	//used to store a pair of numbers
	float x, y;
	float z= 0;
	int index;
};

struct Triangle {
	Triangle() = default;
	Triangle(Point p1, Point p2, Point p3) : p1(p1), p2(p2), p3(p3) {};
	float get_area();
	Point p1, p2, p3;
};

struct Distance_suite {
	//calculates distances between pair of points
	float distance(Point pair, Point pair2);

	//checks if multiple points are on the same line
	bool check_collinear(Point pair1, Point pair2, Point pair3);

	//finds the pair of points closest to first pair
	Point find_shortest_pair(int num_pairs);

	//test suite to test functions
	void calc_area_triangle();
	void run_3_7();
	void run_3_8();
	void run_3_9();
	int main_triagle_point();

};
