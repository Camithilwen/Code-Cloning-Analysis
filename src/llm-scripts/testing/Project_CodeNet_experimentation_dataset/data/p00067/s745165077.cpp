
#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
static const int MAX_N = 12;
int field[MAX_N][MAX_N];
static const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

int stoi(std::string str) {
	int ret;
	std::stringstream ss;
	ss << str;
	ss >> ret;
	return ret;
}

void dfs(int y, int x) {
	field[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		if (0 <= x + dx[i] && x + dx[i] < 12 && 0 <= y + dy[i] && y + dy[i] < 12 && field[y + dy[i]][x + dx[i]] == 1) {
			dfs(y + dy[i], x + dx[i]);
		}
	}
}

void printTable() {
	cout << "------------------" << endl;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			cout << field[i][j];
		}
		cout << endl;
	}
}

int main()
{
	string s = "";
	
	while (cin >> s) {
		int cnt = 0;
		if (s == "")break;
		//input
		for (int i = 0; i < 12; i++)field[0][i] = s[i] - '0';// stoi(s[i]);
		for (int i = 1; i < 12; i++) {
			cin >> s;
			for (int j = 0; j < 12; j++) {
				field[i][j] = s[j] - '0';// stoi(s[j]);
			}
		}
		//printTable();
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				if (field[i][j] == 1) {
					cnt++;
					dfs(i, j);
			//		printTable();
				}
			}
		}	
		cout << cnt << endl;
	
	}


    return 0;
}