#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll K, X;
	cin >> K >> X;

	K--;
	for(ll i = X - K; i <= X + K; i++) {
		cout << i;
		if(i == X + K) {
			cout << endl;
		} else {
			cout << " ";
		}

	}

}
