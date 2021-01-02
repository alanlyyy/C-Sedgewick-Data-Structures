#pragma once
template <class Item>
class STACK_ADT_NO_DUPLICATES {

private:
	Item* s, * t;
	int N;

public:
	STACK_ADT_NO_DUPLICATES(int maxN)
	{
		s = new Item[maxN];
		t = new Item[maxN];

		//initialize each index to null, when stack is empty
		for (int i = 0; i < maxN; i++) {
			t[i] = 0;
		}
	}

	int empty() {
		return N == 0;
	}

	void push(Item item) {
		if (t[item] == 1)
			return;

		s[N++] = item;
		t[item] = 1;
	}

	Item pop() {
		t[s[--N]] = 0;
		return s[N];
	}

};