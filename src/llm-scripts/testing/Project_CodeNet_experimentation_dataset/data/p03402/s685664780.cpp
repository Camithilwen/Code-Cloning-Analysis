#include <iostream>
#include <vector>
using namespace std;
int main(){
	int A, B;
	cin >> A >> B;
	vector<vector<char>> c(100, vector<char>(100));
	for (int i = 0; i < 50; i++){
		for (int j = 0; j < 100; j++){
			c[i][j] = '#';
		}
	}
	for (int i = 50; i < 100; i++){
		for (int j = 0; j < 100; j++){
			c[i][j] = '.';
		}
	}
	for (int i = 0; i < A - 1; i++){
		c[i / 50 * 2][i % 50 * 2] = '.';
	}
	for (int i = 0; i < B - 1; i++){
		c[99 - i / 50 * 2][i % 50 * 2] = '#';
	}
	cout << "100 100" << endl;
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			cout << c[i][j];
		}
		cout << endl;
	}
}