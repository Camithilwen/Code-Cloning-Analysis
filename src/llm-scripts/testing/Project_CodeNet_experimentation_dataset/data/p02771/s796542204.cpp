#include"bits/stdc++.h"
#include<iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define rep(i, c) for(int i = 0; i < (int)c; i++)
const ll inf = 1000000007;

int main() {
	int a, b,c;
	cin >> a >> b >> c;
	if (a != b) {
		if (a==c || b==c) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	else {
		if (a != c) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}