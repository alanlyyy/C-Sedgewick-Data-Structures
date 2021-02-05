#include <iostream>

static int* p;
static int* wt;
static int** k;
int knapsack_bottom_up(int N,int M) {

	//creat knapsack 2D table
	k = new int* [N + 1];
	for (int i = 0; i <= N; i++) {
		k[i] = new int[M+1];
	}

	for (int i = 0; i <= N; i++) {

		for (int w = 0; w <= M; w++) {

			if (i == 0 || w == 0) {
				
				k[i][w] = 0;
			} 
			else if(wt[i] <= w){
				

				int val1 = p[i] + k[i - 1][w - wt[i]];
				int val2 = k[i - 1][w];

				if (val1 > val2) {
					k[i][w] = val1;
				}
				else {
					k[i][w] = val2;
				}
			}
			else {
				k[i][w] = k[i - 1][w];
			}
		}
	}

	int i = N;
	int j = M;

	//pick out items in the optimal solution.
	while (i > 0 && j >= 0) {

		if (k[i][j] == k[i - 1][j]) 
		{
			std::cout << i << " = 0" << std::endl;
			i--;
		}
		else {
			std::cout << i << " = 1" << std::endl;
			j = j - wt[i];
			i--;
		}
	}

	return k[N][M];
}

int main_5_51() {
	p = new int[5];
	p[0] = 0;
	p[1] = 1;
	p[2] = 2;
	p[3] = 5;
	p[4] = 6;

	wt = new int[5];
	wt[0] = 0;
	wt[1] = 2;
	wt[2] = 3;
	wt[3] = 4;
	wt[4] = 5;

	std::cout << knapsack_bottom_up(4, 8) << std::endl;
	return 0;
}