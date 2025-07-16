#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;
	cout << A + B + C + D + E + F - min(A, min(B, min(C, D))) - min(E, F) << endl;
}
