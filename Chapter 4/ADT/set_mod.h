#pragma once
#include <iostream>
#include <iomanip>

class Set {

private:
	int* set_of_num;
	int M;


	void clear_set() {
		delete[] set_of_num;
	}

public:
	Set(int size) {
		M = size;
		set_of_num = new int[M];


		//0 means not in the set , 1 means in the set
		for (int i = 0; i < M; i++) {
			set_of_num[i] = 0;
		}
	}

	Set(const Set& other) {
		
		//deleting existing data before copy other set into current set
		clear_set();

		//create new array of size other.M and copy contents of array
		set_of_num = new int[other.M];

		M = other.M;

		for (int i = 0; i < other.M; i++) {
			set_of_num[i] = other.set_of_num[i];
		}
	}

	Set& operator=(const Set& other) {

		if (this == &other) {
			return *this;
		}

		//deleting existing data before copy other set into current set
		clear_set();

		//create new array of size other.M and copy contents of array
		set_of_num = new int[other.M];

		M = other.M;

		for (int i = 0; i < other.M; i++) {
			set_of_num[i] = other.set_of_num[i];
		}
	}

	~Set() {
		clear_set();
	}

	Set& union_set( const Set& other) {

		int size = 0;
		int small_size = 0;
		bool flag = false;
		if (M > other.M) {

			size = M;
			small_size = other.M;
			flag = true;
		}
		else {
			size = other.M;
			small_size = M;
		}
	

		int* unionset = new int[size];

		//append contents of combined set into unionset
		for (int i = 0; i < small_size; i++) {

			//if the value of both sets are equal  copy the value
			if (other.set_of_num[i] == set_of_num[i])
			{
				unionset[i] = other.set_of_num[i];
			}
			//if the values are not equal default to appending 1
			else {
				unionset[i] = 1;
			}
		}

		//append contents of bigger set into new union set
		for (int i = small_size; i < size; i++) {

			if (flag == true) {
				unionset[i] = set_of_num[i];
			}
			else {
				unionset[i] = other.set_of_num[i];
			}
		}

		//clear current set
		clear_set();

		//set_of_num now points to union set
		set_of_num = unionset;

		M = size;

		return *this;
		
	}

	Set& intersection_set(const Set& other) {

		int size = 0;
		int small_size = 0;
		bool flag = false;

		if (M > other.M) {

			size = M;
			small_size = other.M;
			flag = true;
		}
		else {
			size = other.M;
			small_size = M;
		}


		int* unionset = new int[size];

		//append contents of combined set into unionset
		for (int i = 0; i < small_size; i++) {

			//if the value of both sets are equal  copy the value
			if (other.set_of_num[i] == set_of_num[i])
			{
				unionset[i] = other.set_of_num[i];
			}
			//if the values are not equal default to appending 0
			else {
				unionset[i] = 0;
			}
		}

		//for values that exceed size of smaller set append a 0
		for (int i = small_size; i < size; i++) {
			unionset[i] = 0;
		}

		//clear existing set 
		clear_set();

		//set_of_num now points to union set
		set_of_num = unionset;

		//update the new size
		M = size;

		return *this;
	}


	Set& difference_set(const Set& other) {

		int size = 0;
		int small_size = 0;
		bool flag = false;

		if (M > other.M) {

			size = M;
			small_size = other.M;
			flag = true;
		}
		else {
			size = other.M;
			small_size = M;
		}

		int* diff_set2 = new int[size];

		//append contents of combined set into unionset
		for (int i = 0; i < small_size; i++) {

			//if the value of both sets are equal set to 0
			if (other.set_of_num[i] == set_of_num[i])
			{
				diff_set2[i] = 0;
			}
			//if the values are not equal default to appending 1
			else {
				diff_set2[i] = 1;
			}
		}

		//append contents of bigger set into new union set
		for (int i = small_size; i < size; i++) {

			if (flag == true) {
				diff_set2[i] = set_of_num[i];
			}
			else {
				diff_set2[i] = other.set_of_num[i];
			}
		}

		//delete existing set
		clear_set();

		//set of num now points to a new array diff_set2
		set_of_num = diff_set2;

		//insert new size
		M = size;

		return *this;
	}

	Set& complement_set() {
		//return a copy of complement set.

		//append contents of combined set into unionset
		for (int i = 0; i < M; i++) {

			if (set_of_num[i] == 0) {
				set_of_num[i] = 1;
			}
			else {
				set_of_num[i] = 0;
			}
		}
		return *this;
	}

	void insert_to_set(int val) {

		if (val >= M) {
			std::cout << "number exceeds limit of the set" << std::endl;
		}
		else {
			set_of_num[val] = 1;
		}
	}

	void multiple_insert(int* val,int size) {

		for (int i = 0; i < size; i++) {
			insert_to_set(val[i]);
		}
	}


	void remove_from_set(int val) {
		if (val >= M) {
			std::cout << "number exceeds limit of the set" << std::endl;
		}
		else {
			set_of_num[val] = 0;
		}
	}

	void print_set() {

		for (int i = 0; i < M; i++) {

			if (i != M - 1) {
				std::cout << i << std::setw(3);
			}
			else {
				std::cout << i;
			}
		}
		std::cout << std::endl;

		for (int i = 0; i < M; i++) {
			if (i != M - 1) {
				std::cout << set_of_num[i] << std::setw(3);
			}
			else {
				std::cout << set_of_num[i];
			}
		}
		std::cout << std::endl;
	}
};