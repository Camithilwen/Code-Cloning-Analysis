#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>

bool dfs(char board[8][8], bool v_used[], bool h_used[], bool dr_used[], bool dl_used[], int x, int y, int num) {
	if (num == 8) return true;
	for (int i = 0; i < 8; i++) {
		if (h_used[i]) continue;
		for (int j = 0; j < 8; j++) {
			if (board[i][j] != 'Q') {
				if (!v_used[j] && !h_used[i] && !dr_used[8 - j + i - 1] && !dl_used[i + j]) {
					v_used[j] = h_used[i] = dr_used[8 - j + i - 1] = dl_used[i + j] = true;
					board[i][j] = 'Q';
					bool ret = dfs(board, v_used, h_used, dr_used, dl_used, i, j, num + 1);
					if (ret) return true;
					v_used[j] = h_used[i] = dr_used[8 - j + i - 1] = dl_used[i + j] = false;
					board[i][j] = '.';
				}
			}
		}
	}
	return false;
}

int main() {
	int n;
	bool v_used[8], h_used[8], dr_used[16], dl_used[16];
	char board[8][8];

	// ?????????????????????
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = '.';
		}
		v_used[i] = h_used[i] = false;
	}

	for (int i = 0; i < 16; i++) {
		dr_used[i] = dl_used[i] = false;
	}

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		std::cin >> x >> y;
		board[x][y] = 'Q';

		v_used[y] = true;
		h_used[x] = true;
		dr_used[8 - y + x - 1] = true;
		dl_used[x + y] = true;
	}

	if (n == 8) {
		for (int k = 0; k < 8; k++) {
			for (int l = 0; l < 8; l++) {
				std::cout << board[k][l];
			}
			std::cout << std::endl;
		}
		return 0;
	}

	for (int i = 0; i < 8; i++) {
		if (h_used[i]) continue;
		for (int j = 0; j < 8; j++) {
			if (board[i][j] != 'Q') {
				if (!v_used[j] && !h_used[i] && !dr_used[8 - j + i - 1] && !dl_used[i + j]) {
					v_used[j] = h_used[i] = dr_used[8 - j + i - 1] = dl_used[i + j] = true;
					board[i][j] = 'Q';
					bool ret = dfs(board, v_used, h_used, dr_used, dl_used, i, j, n + 1);
					if (ret) {
						for (int k = 0; k < 8; k++) {
							for (int l = 0; l < 8; l++) {
								std::cout << board[k][l];
							}
							std::cout << std::endl;
						}
						return 0;
					}
					v_used[j] = h_used[i] = dr_used[8 - j + i - 1] = dl_used[i + j] = false;
					board[i][j] = '.';
				}
			}
		}
	}


}