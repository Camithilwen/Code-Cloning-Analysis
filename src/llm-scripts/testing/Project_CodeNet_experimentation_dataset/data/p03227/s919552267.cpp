#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	string S;
	cin >> S;

	int s_Len = S.length();

	if (s_Len == 3) {
		reverse(S.begin(), S.end());
	}

	cout << S << endl;

}


