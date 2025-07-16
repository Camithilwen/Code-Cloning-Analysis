#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool furui[10010];
vector<int> prime;
vector<int> twin;

void mkprime() {
	for(int i = 0; i < 10010; i++) furui[i] = true;
	furui[0] = furui[1] = false;
	for(int i = 0; i < 10010; i++) {
		if(furui[i]) {
			prime.push_back(i);
			for(int j = i * 2; j < 10010; j += i) {
				furui[j] = false;
			}
		}
	}
	for(int i = 0; i < prime.size() - 1; i++) {
		if(prime[i + 1] - prime[i] == 2)
			twin.push_back(prime[i + 1]);
	}
	sort(twin.begin(), twin.end());
}

int main() {
	int n;
	mkprime();
	while(cin >> n, n) {
		vector<int>::iterator iter;
		iter = upper_bound(twin.begin(), twin.end(), n);
		cout << *(iter-1) - 2 << " " << *(iter-1) << endl;
	}
}