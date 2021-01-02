#include "queue_array_interface.h"
#include <iostream>

void queue_client(){

	int M = 2;
	int N = 10;

	//create an array of queues
	Queue_array<int>* queues = new Queue_array<int>[M];

	//initialize each queue in the array of queues
	for (int i = 0; i < M; i++) {
		queues[i].set_array(N);
	}

	for (int i = 0; i < N; i++){

		//randonly pick number to select and put in queue
		int in = rand() % M, out = rand() % M;

		queues[in].put(i);

		std::cout << i << " in" <<std::endl;

		//if current queues is not empty pop element out
		if (!queues[out].empty()) {
			std::cout << queues[out].get() << " out" << std::endl;
		}

		for (int k = 0; k < M; k++) {
			Queue_array<int> q = queues[k];
			std::cout << k << ": ";

			while (!q.empty()) {
				std::cout << q.get() << " ";
			}
		}
	}

	//deallocate memory from array queue
	delete[] queues;

}

void test_4_71() {
	//test if destructor is working.

	int M = 2;
	int N = 10;

	//create an array of queues
	Queue_array<int>* queues = new Queue_array<int>[M];

	//initialize each queue in the array of queues
	for (int i = 0; i < M; i++) {
		queues[i].set_array(N);
	}

	//push 0,1,2,...10 to arrays 1 and 2
	for (int i = 0; i < M; i++) {

		for (int j = 0; j < N; j++)
			queues[i].put(j);

		std::cout << i << " in" << std::endl;
	}

	//pop all elements from arrays 1 and 2
	for (int i = 0; i < M; i++) {

		while (!queues[i].empty()) {
			std::cout << queues[i].get() << " ";
		}
		std::cout << std::endl;
	}

	//deallocate memory from array queue
	delete[]queues;

	//std::cout << queues[0].get() << "test get" << std::endl;
}

int main_4_71() {
	queue_client();
	//test_4_71();
	return 0;
}