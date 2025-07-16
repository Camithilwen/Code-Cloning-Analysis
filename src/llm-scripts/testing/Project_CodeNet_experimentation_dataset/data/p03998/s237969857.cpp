#include<bits/stdc++.h>
using namespace std;

int main()
{
	string game[3];
	cin >> game[0] >> game[1] >> game[2];
	int turn = 0;
	int length[] = {game[0].length(), game[1].length(), game[2].length()};
	int indices[] = {0, 0, 0};
	while(true) {
		int curr = indices[turn]++;
		if(indices[turn] > length[turn]) break;
		turn = game[turn][curr] - 'a';
	}
	cout << char(turn + 'A');
}
