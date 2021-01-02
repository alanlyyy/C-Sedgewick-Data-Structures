#include <time.h>
#include "random_queue.h"
#include <iostream>

void lottery() {
	int N = 100;

	//set the seed to randomize time
	srand(time(NULL));

	random_queue_array<int> qa(100);

	for (int i = 0; i < N; i++) {
		qa.put_in_back(i);
	}

	int j = 0;
	while (j < 5) {
		qa.get_random();
		j++;
	}

	//print 5th element
	std::cout << qa.get_random() << std::endl;
}
int main_4_50() {
	lottery();
	return 0;
}