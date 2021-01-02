#pragma once
#include <iostream>

template<class Number>
class Matrix {

private:
	Number** multi_dim_array;
	int row = 0;
	int col = 0;

	void clear_matrix() {

		for (int i = 0; i < row; i++) {

			//delete each col 
			delete[] multi_dim_array[i];
		}

		//delete all rows
		delete [] multi_dim_array;
	}

public:

	Matrix(int r, int c) {
		row = r;
		col = c;

		//create r rows
		multi_dim_array = new Number * [r];

		for (int i = 0; i < row; i++) {

			//for each row initialize c cols
			multi_dim_array[i] = new Number[c];
		}

		// Initializing elements of matrix.
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				multi_dim_array[i][j] = 0;
			}
		}

	}

	Matrix(const Matrix& other) {
		//copy constructor

		//deallocate existing memory
		clear_matrix();

		//create a new multi dim array
		multi_dim_array = new Number * [other.row];

		row = other.row;
		col = other.col;

		for (int i = 0; i < row; i++) {

			//for each row initialize c cols
			multi_dim_array[i] = new Number[other.col];
		}

		// Initializing elements of matrix.
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				multi_dim_array[i][j] = other.multi_dim_array[i][j];
			}
		}
	}

	Matrix& operator=(const Matrix& other) {
		//copy constructor

		if (this == &other) {
			return *this;
		}

		//deallocate existing memory
		clear_matrix();

		//create a new multi dim array
		multi_dim_array = new Number * [other.row];

		row = other.row;
		col = other.col;

		for (int i = 0; i < row; i++) {

			//for each row initialize c cols
			multi_dim_array[i] = new Number[other.col];
		}

		// Initializing elements of matrix mult to 0.
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				multi_dim_array[i][j] = other.multi_dim_array[i][j];
			}
		}

		return *this;
	}

	Matrix& operator+=(Number val) {
		//add scalar to matrix

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				multi_dim_array[i][j] += val;
			}
		}
	}

	Matrix& operator*=(Number val) {
		//allows for scalar to multiply with matrice

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				multi_dim_array[i][j] *= val;
			}
		}
	}

	friend Matrix operator*(const Matrix& curr, const Matrix& other) {

		if (curr.col != other.row) {
			std::cout << "Error, cannot multiply both matrices." << std::endl;
			return curr;
		}

		Matrix<Number> mult(curr.row, other.col);

		int i, j, k;

		// Initializing elements of matrix mult to 0.
		for (i = 0; i < curr.row; ++i)
		{
			for (j = 0; j < other.col; ++j)
			{
				mult.multi_dim_array[i][j] = 0;
			}
		}

		// Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
		for (i = 0; i < curr.row; ++i)
		{
			for (j = 0; j < other.col; ++j)
			{
				for (k = 0; k < curr.col; ++k)
				{
					mult.multi_dim_array[i][j] += (curr. multi_dim_array[i][k] * other.multi_dim_array[k][j]);
				}
			}
		}

		return mult;
	}

	friend Matrix operator/(const Matrix& curr, const Matrix& other) {


		if ((curr.row != other.row) || (curr.col != other.col)) {
			std::cout << "Error, cannot add both matrices, incorrect dimensions." << std::endl;
			return curr;
		}

		Matrix<Number> mult(curr.row, curr.col);

		int i, j, k;

		// Initializing elements of matrix mult to 0.
		for (i = 0; i < curr.row; ++i)
		{
			for (j = 0; j < curr.col; ++j)
			{
				mult.multi_dim_array[i][j] = 0;
			}
		}

		// Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
		for (i = 0; i < curr.row; ++i)
		{
			for (j = 0; j < curr.col; ++j)
			{

				mult.multi_dim_array[i][j] += (curr.multi_dim_array[i][j] / other.multi_dim_array[i][j]);

			}
		}

		return mult;
	}

	friend Matrix operator+(const Matrix& curr, const Matrix& other) {


		if ((curr.row != other.row) || (curr.col != other.col)) {
			std::cout << "Error, cannot add both matrices, incorrect dimensions." << std::endl;
			return curr;
		}

		Matrix<Number> mult(curr.row, curr.col);

		int i, j, k;

		// Initializing elements of matrix mult to 0.
		for (i = 0; i < curr.row; ++i)
		{
			for (j = 0; j < curr.col; ++j)
			{
				mult.multi_dim_array[i][j] = 0;
			}
		}

		// Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
		for (i = 0; i < curr.row; ++i)
		{
			for (j = 0; j < curr.col; ++j)
			{

				mult.multi_dim_array[i][j] += (curr.multi_dim_array[i][j] + other.multi_dim_array[i][j]);

			}
		}

		return mult;
	}

	friend Matrix operator-(const Matrix& curr, const Matrix& other) {


		if ((curr.row != other.row) || (curr.col != other.col)) {
			std::cout << "Error, cannot add both matrices, incorrect dimensions." << std::endl;
			return curr;
		}

		Matrix<Number> mult(curr.row, curr.col);

		int i, j, k;

		// Initializing elements of matrix mult to 0.
		for (i = 0; i < curr.row; ++i)
		{
			for (j = 0; j < curr.col; ++j)
			{
				mult.multi_dim_array[i][j] = 0;
			}
		}

		// Multiplying matrix firstMatrix and secondMatrix and storing in array mult.
		for (i = 0; i < curr.row; ++i)
		{
			for (j = 0; j < curr.col; ++j)
			{

				mult.multi_dim_array[i][j] += (curr.multi_dim_array[i][j] - other.multi_dim_array[i][j]);

			}
		}

		return mult;
	}
	~Matrix() {
		clear_matrix();
	}

	void insert_val(int r, int c, Number val) {

		if (r < row && c < col) {
			multi_dim_array[r][c] = val;
		}
		else {
			std::cout << "Index out of bounds." << std::endl;
		}
	}

	void print_elements() {
		int i, j;

		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				std::cout << multi_dim_array[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
};