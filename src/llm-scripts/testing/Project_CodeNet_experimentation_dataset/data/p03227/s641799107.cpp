#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	string S;
	cin >> S;

	if (S.length() == 3) {
		reverse(S.begin(), S.end());
		cout << S << endl;
	}
	else {
		cout << S << endl;
	}
}
