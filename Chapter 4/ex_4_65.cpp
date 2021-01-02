#include "Poker_hand.h"


int compare_straight_different_rank() {

	//Hand = K J 9 4 6
	Playing_Card a = Playing_Card(10, 1);
	Playing_Card b = Playing_Card(11, 2);
	Playing_Card c =Playing_Card(12, 3);
	Playing_Card d = Playing_Card(13, 4);
	Playing_Card e =Playing_Card(1, 2);

	Playing_Card f = Playing_Card(2, 1);
	Playing_Card g = Playing_Card(3, 2);
	Playing_Card h = Playing_Card(4, 3);
	Playing_Card i = Playing_Card(5, 4);
	Playing_Card j = Playing_Card(6, 2);


	//test adding new cards to hand
	Poker_hand hand1, hand2;
	hand1 += a;
	hand1 += b;
	hand1 += c;
	hand1 += d;
	hand1 += e;

	hand2 += f;
	hand2 += g;
	hand2 += h;
	hand2 += i;
	hand2 += j;

	//test printing hand
	std::cout << hand1 << std::endl;
	std::cout << hand2 << std::endl;


	//test sort hand
	//hand1.sort_hand();
	//std::cout << hand1 << std::endl;

	std::cout << (hand1 > hand2) << std::endl;
	return 0;
}

int compare_straight_different_suit() {

	//Hand = K J 9 4 6
	Playing_Card a = Playing_Card(10, 1);
	Playing_Card b = Playing_Card(11, 1);
	Playing_Card c = Playing_Card(12, 1);
	Playing_Card d = Playing_Card(13, 1);
	Playing_Card e = Playing_Card(1, 1);

	Playing_Card f = Playing_Card(10, 2);
	Playing_Card g = Playing_Card(11, 2);
	Playing_Card h = Playing_Card(12, 2);
	Playing_Card i = Playing_Card(13, 2);
	Playing_Card j = Playing_Card(1, 2);


	//test adding new cards to hand
	Poker_hand hand1, hand2;
	hand1 += a;
	hand1 += b;
	hand1 += c;
	hand1 += d;
	hand1 += e;

	hand2 += f;
	hand2 += g;
	hand2 += h;
	hand2 += i;
	hand2 += j;

	//test printing hand
	std::cout << hand1 << std::endl;
	std::cout << hand2 << std::endl;


	//test sort hand
	//hand1.sort_hand();
	//std::cout << hand1 << std::endl;

	std::cout << (hand1 > hand2) << std::endl;
	return 0;
}

int compare_single_high_card() {

	//Hand = K J 9 4 6
	Playing_Card a = Playing_Card(10, 1);
	Playing_Card b = Playing_Card(2, 1);
	Playing_Card c = Playing_Card(3, 2);
	Playing_Card d = Playing_Card(4, 4);
	Playing_Card e = Playing_Card(5, 4);

	Playing_Card f = Playing_Card(10, 2);
	Playing_Card g = Playing_Card(2, 2);
	Playing_Card h = Playing_Card(3, 1);
	Playing_Card i = Playing_Card(4, 3);
	Playing_Card j = Playing_Card(5, 2);


	//test adding new cards to hand
	Poker_hand hand1, hand2;
	hand1 += a;
	hand1 += b;
	hand1 += c;
	hand1 += d;
	hand1 += e;

	hand2 += f;
	hand2 += g;
	hand2 += h;
	hand2 += i;
	hand2 += j;

	//test printing hand
	std::cout << hand1 << std::endl;
	std::cout << hand2 << std::endl;


	//test sort hand
	//hand1.sort_hand();
	//std::cout << hand1 << std::endl;

	std::cout << (hand1 > hand2) << std::endl;
	return 0;
}

int compare_two_pairs() {

	//Hand = K J 9 4 6
	Playing_Card a = Playing_Card(10, 1);
	Playing_Card b = Playing_Card(10, 2);
	Playing_Card c = Playing_Card(3, 2);
	Playing_Card d = Playing_Card(5, 3);
	Playing_Card e = Playing_Card(5, 4);

	Playing_Card f = Playing_Card(10, 3);
	Playing_Card g = Playing_Card(10, 4);
	Playing_Card h = Playing_Card(3, 2);
	Playing_Card i = Playing_Card(6, 4);
	Playing_Card j = Playing_Card(6, 2);


	//test adding new cards to hand
	Poker_hand hand1, hand2;
	hand1 += a;
	hand1 += b;
	hand1 += c;
	hand1 += d;
	hand1 += e;

	hand2 += f;
	hand2 += g;
	hand2 += h;
	hand2 += i;
	hand2 += j;

	//test printing hand
	std::cout << hand1 << std::endl;
	std::cout << hand2 << std::endl;


	//test sort hand
	//hand1.sort_hand();
	//std::cout << hand1 << std::endl;

	std::cout << (hand1 > hand2) << std::endl;
	return 0;
}

int compare_single_pair_two_pair() {

	//Hand = K J 9 4 6
	Playing_Card a = Playing_Card(10, 1);
	Playing_Card b = Playing_Card(10, 2);
	Playing_Card c = Playing_Card(3, 2);
	Playing_Card d = Playing_Card(4, 4);
	Playing_Card e = Playing_Card(5, 4);

	Playing_Card f = Playing_Card(10, 3);
	Playing_Card g = Playing_Card(10, 4);
	Playing_Card h = Playing_Card(3, 2);
	Playing_Card i = Playing_Card(6, 4);
	Playing_Card j = Playing_Card(6, 2);


	//test adding new cards to hand
	Poker_hand hand1, hand2;
	hand1 += a;
	hand1 += b;
	hand1 += c;
	hand1 += d;
	hand1 += e;

	hand2 += f;
	hand2 += g;
	hand2 += h;
	hand2 += i;
	hand2 += j;

	//test printing hand
	std::cout << hand1 << std::endl;
	std::cout << hand2 << std::endl;


	//test sort hand
	//hand1.sort_hand();
	//std::cout << hand1 << std::endl;

	std::cout << (hand1 > hand2) << std::endl;
	return 0;
}
int main_4_65() {
	compare_straight_different_rank();
	compare_straight_different_suit();
	compare_single_high_card();
	compare_two_pairs();
	compare_single_pair_two_pair();
	return 0;
}