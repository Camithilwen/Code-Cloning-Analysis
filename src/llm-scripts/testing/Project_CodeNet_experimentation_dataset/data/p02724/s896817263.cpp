#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
	long long X, Y;
	cin >> X;
	Y = X;
	long long happy = 0;
	X = X / 500;
	happy += 1000 * X;
	Y -= X * 500;
	Y = Y / 5;
	happy += Y * 5;
	cout << happy << endl;
}
