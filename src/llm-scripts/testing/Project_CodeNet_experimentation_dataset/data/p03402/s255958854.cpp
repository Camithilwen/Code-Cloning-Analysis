#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

string S[100];
int main()
{
	int A, B;
	cin >> A >> B;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 100; j++) {
			S[i].push_back('.');
		}
	}
	for (int i = 50; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			S[i].push_back('#');
		}
	}
	A--; B--;
	int i = 99, j = 2;
	while (A > 0) {
		S[i][j] = '.';
		j += 4;
		if (j >= 100) {
			i--;
			j = i % 2 * 2;
		}
		A--;
	}
	i = 0; j = 0;
	while (B > 0) {
		S[i][j] = '#';
		j += 4;
		if (j >= 100) {
			i++;
			j = i % 2 * 2;
		}
		B--;
	}
	cout << 100 << " " << 100 << endl;
	for (int i = 0; i < 100; i++) {
		cout << S[i] << endl;
	}
}