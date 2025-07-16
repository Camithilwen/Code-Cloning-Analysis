#include<iostream>

bool rc(int);
bool board[64]{}, row[8]{}, column[8]{}, right_down[15]{}, left_down[15]{};

int main()
{
	int k, r, c;

	std::cin >> k;
	for (int i = 0; i < k; ++i)
	{
		std::cin >> r >> c;
		board[r * 8 + c] = true;
		row[r] = column[c] = true;
		right_down[7 + c - r] = left_down[r + c] = true;
	}

	rc(k);
	for (int i = 0; i < 64; ++i)
	{
		if (board[i])
			std::cout << 'Q';
		else
			std::cout << '.';
		if (i % 8 == 7)
			std::cout << std::endl;
	}

	return 0;
}

bool rc(int k)
{
	if (k == 8)
		return true;

	for (int i = 0; i < 8; ++i)
	{
		if (row[i]) continue;
		row[i] = true;
		for (int j = 0; j < 8; ++j)
		{
			if (column[j] || right_down[7 + j - i] || left_down[i + j])
				continue;
			column[j] = right_down[7 + j - i] = left_down[i + j] = true;
			board[i * 8 + j] = true;

			if (rc(k + 1))
				return true;

			column[j] = right_down[7 + j - i] = left_down[i + j] = false;
			board[i * 8 + j] = false;
		}
		row[i] = false;
		return false;
	}
}
