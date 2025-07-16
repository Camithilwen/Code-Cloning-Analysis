#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int main() {
	vector<int> W, K;
	int dommy;
	for (int i = 0; i < 10; ++i) {
		cin >> dommy;
		W.push_back(dommy);
	}
	sort(W.begin(), W.end(), greater<int>());
	for (int i = 0; i < 10; ++i) {
		cin >> dommy;
		K.push_back(dommy);
	}
	sort(K.begin(), K.end(), greater<int>());
	int Wpoint = 0, Kpoint = 0;
	for (int i = 0; i < 3; ++i) {
		Wpoint += W[i];
	}
	for (int i = 0; i < 3; ++i) {
		Kpoint += K[i];
	}
	cout << Wpoint << ' ' << Kpoint << endl;
	return 0;
}