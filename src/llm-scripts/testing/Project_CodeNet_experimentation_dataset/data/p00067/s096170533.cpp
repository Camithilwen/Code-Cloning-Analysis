#define _CRT_SECURE_NO_WARNINGS

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<list>
#include<math.h>
#include<stack>
#include<queue>

using namespace std;

queue<int> q;
list<int> l;
int *map = new int[12 * 12 * 20];
static int count;

void loop(int i){
	map[i] = 0;
	if (i / 12 > 0) {
		if (map[i - 12] == 1) {
			loop(i - 12);
		}
	}
	if (i / 12 < 11) {
		if (map[i + 12] == 1) {
			loop(i + 12);
		}
	}
	if (i % 12 > 0) {
		if (map[i - 1] == 1) {
			loop(i - 1);
		}
	}
	if (i % 12 < 11) {
		if (map[i + 1] == 1) {
			loop(i + 1);
		}
	}
}

int main(int argc, char **argv)
{
	int count = 0;
	string str;

	while (cin >> str) {
		for (int j = 0; j < 12; j++) {
			map[j] = str[j] - '0';
		}
		for (int i = 1; i < 12 && cin >> str; i++) {
			for (int j = 0; j < 12; j++) {
				map[i * 12 + j] = str[j] - '0';
			}
		}
		count = 0;
		for (int i = 0; i < 12 * 12; i++) {
			if (map[i] == 1) {
				loop(i);
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}