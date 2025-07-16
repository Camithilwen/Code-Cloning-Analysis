#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int N, X, T;
	cin >> N >> X >> T;
	int S = 0;
	S += N / X * T;
	if (N % X >= 1) {
		S += T;
	}
	cout << S << endl;
}