#include <iostream>
#include<vector>
#include<array>
#include<cmath>
#include <algorithm>

using namespace std;


int main() {
	// 初期処理(iostream軽くする)
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	string n;
	cin >> n;

	if (n.find("7") != string::npos) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	
	return 0;
}