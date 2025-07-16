#include <iostream>
#define SIZE 8

void threaten(int board[][SIZE], int x, int y)
{
	for (int i=0; i<SIZE; i++) {
		board[i][y]++; board[x][i]++;
	}
	for (int i=-x; i<SIZE-x; i++) {
		if (0 <= y+i && y+i < SIZE) board[x+i][y+i]++;
		if (0 <= y-i && y-i < SIZE) board[x+i][y-i]++;
	}
	board[x][y]+=100;
}

void unthreaten(int board[][SIZE], int x, int y)
{
	for (int i=0; i<SIZE; i++) {
		board[i][y]--; board[x][i]--;
	}
	for (int i=-x; i<SIZE-x; i++) {
		if (0 <= y+i && y+i < SIZE) board[x+i][y+i]--;
		if (0 <= y-i && y-i < SIZE) board[x+i][y-i]--;
	}
	board[x][y]-=100;
}

bool solve(int board[][SIZE], int rest)
{
	if (rest==0) return true;
	
	for (int i=0; i<SIZE; i++) {
		for (int j=0; j<SIZE; j++) {
			if (board[i][j]>0) continue;
			threaten(board, i, j);
			if (solve(board, rest-1)) return true;
			unthreaten(board, i, j);
		}
	}
	return false;
}

int main()
{
	int board[SIZE][SIZE];
	for (int i=0; i<SIZE; i++) {
		for (int j=0; j<SIZE; j++) board[i][j] = 0;
	}
	
	int k; std::cin >> k;
	for (int i=0; i<k; i++) {
		int x, y;
		std::cin >> x >> y;
		threaten(board, x, y);
	}
	
	solve(board, SIZE-k);
	
	for (int i=0; i<SIZE; i++) {
		for (int j=0; j<SIZE; j++) {
			if (board[i][j] < 100) std::cout << ".";
			else std::cout << "Q";
		}
		std::cout << std::endl;
	}
	
	return 0;
}

