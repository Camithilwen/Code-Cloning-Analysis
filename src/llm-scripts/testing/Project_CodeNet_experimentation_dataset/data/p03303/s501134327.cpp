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
	int w;
	cin >> w;

	for (int i = 0; i < S.length(); i++) {
		if (i % w == 0) {
			cout << S[i];
		}
	}
	cout << endl;

}



