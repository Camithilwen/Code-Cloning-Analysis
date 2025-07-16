#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	if (S.length() == 3) reverse(S.begin(), S.end());
	cout << S << "\n";
	return 0;
}
