#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

bool isPrime[100010];
void set_prime() {
	for (int i = 1; i <= 100000; i++) {
		isPrime[i] = true;
	}
	isPrime[0] = false; isPrime[1] = false;
	for (int i = 2; i * i <= 100000; i++) {
		int j = 2;
		while (i * j <= 100000) {
			isPrime[i * j] = false;
			j++;
		}
	}
}

int main()
{
	int N;
	cin >> N;
	set_prime();
	int j = 2;
	for (int i = 0; i < N; i++) {
		while (true) {
			if (isPrime[j] && j % 5 == 1) {
				cout << j++ << " ";
				break;
			}
			j++;
		}
	}
	cout << endl;
}
