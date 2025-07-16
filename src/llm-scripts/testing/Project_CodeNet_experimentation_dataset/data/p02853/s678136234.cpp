#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int X, Y;
	cin >> X >> Y;
	
	int total = 0;
	if (X == 1 && Y == 1) {
		total = 300000 * 2 + 400000;
		cout << total << endl;
		return 0;
	}

	if (X == 1) {
		total += 300000;
	}
	else if (X == 2) {
		total += 200000;
	}
	else if (X == 3) {
		total += 100000;
	}

	if (Y == 1) {
		total += 300000;
	}
	else if (Y == 2) {
		total += 200000;
	}
	else if (Y == 3) {
		total += 100000;
	}

	cout << total << endl;

}




