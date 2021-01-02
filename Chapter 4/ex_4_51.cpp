#include "random_queue.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <time.h>

struct playing_card {
	char rank;
	playing_card(char r=0) {
		rank = r;
	}
};
void poker(int num_hands) {
	int N = num_hands;

	//initialize hand array with all cards equal to nullptr
	playing_card* hand = new playing_card[num_hands]();

	//tracks number of hands played
	int num_cycles = 0;

	//shuffle string
	std::string s1 = "AAAA222233334444555566667777888899990000JJJJQQQQKKKK";
	random_shuffle(s1.begin(), s1.end());

	random_queue_array<playing_card> qa(N);

	for (int i = 0; i < num_hands; i++) {
		qa.put_in_back(playing_card(s1[i]));
	}


	while (num_cycles < num_hands)
	{
		//get playing cards from hand
		for (int i = 0; i < num_hands; i++) {

			//draw card up to num_hands
			hand[i] = qa.get_random();
		}

		//print hand, every 5 cards increase num_cycles
		for (int card = 1; card <= num_hands; card++) {
			std::cout << hand[card - 1].rank << " ";

			if ((card % 5) == 0) {
				std::cout << '\n' << std::endl;
				num_cycles += 1;
			}

			//re-insert card back into deck
			qa.put_in_back(hand[card - 1]);

			//reset card in the hand
			hand[card - 1] = 0;
		}

		std::cout << '\n';
	}
}
int main_ex_4_51() {
	//set the seed to randomize time
	srand(time(NULL));

	poker(13);
	return 0;
}