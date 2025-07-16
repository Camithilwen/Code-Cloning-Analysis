#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int H, W, N;
	cin >> H >> W >> N;

	if (H >= W) {
		if (N % H == 0) {
			cout << N / H << endl;
		}
		else {
			cout << N / H + 1 << endl;
		}
	}
	else {
		if (N % W == 0) {
			cout << N / W << endl;
		}
		else {
			cout << N / W + 1 << endl;
		}
	}
}




