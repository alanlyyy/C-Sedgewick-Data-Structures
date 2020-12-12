#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include "C:\Users\Alan\source\repos\Sedgewick Algorithms and Data Structures\Algorithms_1_1\binary_search.cpp"

int num_unique_ints(int N) {
	//ex3.16 count number of different  integers less than 1000 that appear on the input stream
	//input all numbers into array or vector of size N
	//sort all numbers by ascdending order
	//look at each index previous and next to find duplicates, remove current element if duplicate
	//return length of vector

	std::vector<int> ivec;
	int num_unique = 0;

	for (int index = 0; index < N; index++) {

		//generate a num between 0 and 1000
		int num = rand() % 1000;

		int count_unique = 0;
		//std::cin >> num;

		if (num < 1000) {
			ivec.push_back(num);
		}
	}

	//sort the vector in ascending order
	std::sort(ivec.begin(), ivec.end());

	int index;

	//track number of elements deleted to correct end condition of loop
	int num_deleted = 0;

	for (index = 1; index < N-1-num_deleted; index++) {
		
		//if current value is equal to prev value or equal to next value
		if ((ivec[index] == ivec[index - 1]) || (ivec[index] == ivec[index + 1])) {

			//delete diplicate element
			ivec.erase(ivec.begin() + index);
			num_deleted += 1;

			//correct the index to previous index to account for deletion, next iteration goes back to current index position
			index -= 1;
		}
	}

	return (ivec.end() - ivec.begin());
}
int num_unique_ints_rand_generator(int N) {
	//ex3_17 -- count the number of integers between 0 and 1000 generated before a duplicate is generated
	//randomly generate a number between 0 and 1000
	//insert unique numbers into the vector
	//if duplicate found break out of loop
	//if outside 0 and 1000 skip

	std::vector<int> ivec;
	int num_unique = 0;

	for (int index = 0; index < N; index++) {

		int num = rand() % 1000;

		//if num is between 0 and 1000
		if (num >0 && num < 1000) {

			//sort the vector in ascending order
			std::sort(ivec.begin(), ivec.end());

			BinarySearch bs = BinarySearch();

			//if number is not found in the vector, insert number into vector
			if (bs.rank_recursive(num, ivec) == -1) {

				//insert num into ivec because num is not found.
				ivec.push_back(num);
			}
			//if number is duplicate found in vector , break out of loop
			else {
				break;
			}
		}
	}
	//return total count of elements found in list
	return (ivec.end() - ivec.begin() - 1);
}

int num_unique_ints_rand_count(){
	//ex3_18 -- count number of intergers generated to get all unique numbers between 0 and 1000
	//randomly generate a number between 0 and 1000
	//insert numbers into the vector
	//if duplicate found break out of loop
	//if outside 0 and 1000 skip

	int arr[1000] = { 0 };
	int num_unique = 0;
	int count_nums = 0;

	while (num_unique < 1000)
	{
		int num = rand() % 1000;

		//if num is between 0 and 1000
		if (num >= 0 && num < 1000) {

			count_nums += 1;

			//is num accounted for in the array?
			if (arr[num] == 0)
			{
				arr[num] = 1;

				//update the counter to account for unique num
				num_unique += 1;
			}
		}
	}
	//return total count of elements found in list
	return count_nums;
}

int main_rand_num() {

	/* initialize random seed: */
	//so we get generate random numbers using rand() during every compilation.
	srand(time(NULL));

	std::cout << "3.16 num unique: " << (num_unique_ints(100)) << std::endl;
	std::cout << "3.17 num unique: " << (num_unique_ints_rand_generator(100))<<std::endl;
	std::cout << "3.18 num unique: " << num_unique_ints_rand_count() << std::endl;
	return 0;
}