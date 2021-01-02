#pragma once
#include <iostream>
#include <vector>

template <class Number>
class Vec {

private: 
	std::vector<Number> current_vec;
	int N;

	void clear_vec() {
		current_vec.clear();
	}

public:
	Vec<Number>(int val) {
		//default constructor
		N = 0;
	}

	Vec<Number>(const Vec& other) {
		//copy constructor

		N = other.N;

		//clear existing vec
		clear_vec();

		//copy elements of vec
		for (int i = 0; i < other.N; i++) {
			current_vec.push_back(other.current_vec[i]);
		}
	}

	Vec& operator=(const Vec& other) {
		//copy operator
		if (this == &other) {
			return *this;
		}
		N = other.N;
		//clear existing vec
		clear_vec();

		//copy elements of vec
		for (int i = 0; i < other.N; i++) {
			current_vec.push_back(other.current_vec[i]);
		}

		return *this;
	}

	~Vec<Number>() {
		//destructor
		clear_vec();
	}

	void push(Number val) {
		current_vec.push_back(val);
		N++;
	}

	Number get() {

		if (N > 0) {

			N--;
			return current_vec.pop();
		}
		else {
			return 0;
		}
	}

	Vec& operator+=(const Vec& other) {
		//add each element of other into current vec
		for (int i = 0; i < other.N; i++) {
			current_vec[i] += other.current_vec[i];
		}

		return *this;
	}

	Vec& operator+=(Number val) {
		//add a constant to all members of vec
		for (int i = 0; i < N; i++) {
			current_vec[i] += val;
		}

		return *this;
	}

	Vec& operator*=(const Vec& other) {
		for (int i = 0; i < other.N; i++) {
			current_vec[i] *= other.current_vec[i];
		}

		return *this;
	}

	Vec& operator*=(Number val) {
		for (int i = 0; i < N; i++) {
			current_vec[i] *= val;
		}

		return *this;
	}

	void print_elements() {
		for (int i = 0; i < N; i++) {
			std::cout << current_vec[i] << " ";
		}

		std::cout << std::endl;
	}
};