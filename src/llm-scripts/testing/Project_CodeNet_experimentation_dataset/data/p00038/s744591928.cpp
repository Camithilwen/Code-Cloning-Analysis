#include <bits/stdc++.h>

using namespace std;

bool isStraight(vector<int> v, int s) {
	for (int i = 1; i < v.size(); ++i) {
		if (v[(s+i)%v.size()] != (v[(s+i-1+v.size())%v.size()]+1)%13) {
			return false;
		}
	}
	return true;
}
bool isStraight(vector<int> v) {
	return isStraight(v, 0) || (v[0] == 0 && isStraight(v, 1));
}
int main() {
	vector<int> a(5);
	while ( scanf("%d,%d,%d,%d,%d", &a[0], &a[1], &a[2], &a[3], &a[4]) != EOF ) {
		for (int i = 0; i < a.size(); ++i) {
			--a[i];
		}
		sort(a.begin(), a.end());
		vector<int> v(1, 1);
		int prev = a[0];
		for (int i = 1; i < a.size(); ++i) {
			if (prev == a[i]) {
				++v[v.size()-1];
			}
			else {
				v.push_back(1);
				prev = a[i];
			}
		}
		sort(v.begin(), v.end(), greater<int>());
		if (v[0] >= 4) {
			cout << "four card" << endl;
		}
		else if (v.size() >= 2 && v[0] >= 3 && v[1] >= 2) {
			cout << "full house" << endl;
		}
		else if ( isStraight(a) ) {
			cout << "straight" << endl;
		}
		else if (v[0] >= 3) {
			cout << "three card" << endl;
		}
		else if (v.size() >= 2 && v[1] >= 2) {
			cout << "two pair" << endl;
		}
		else if (v[0] >= 2) {
			cout << "one pair" << endl;
		}
		else {
			cout << "null" << endl;
		}
		
	}
}