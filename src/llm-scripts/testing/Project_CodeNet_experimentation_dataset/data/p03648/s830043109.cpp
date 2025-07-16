#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using pii = pair<int,int>;
#define ALL(x) (x).begin(),(x).end()

int main(){
	ll K;
	cin >> K;
	ll N = 50;
	vector<ll> A(N);
	// K/N周回す
	for(int i=0;i<N;i++) {
		A[i] = (N-1) + K/N;
	}
	// あまりの処理
	ll d = K % N;
	for(int i=0;i<d;i++) {
		A[i] += N;
		for(int j=0;j<N;j++) {
			if(i == j) continue;
			A[j]--;
		}
	}

	cout << N << endl;
	for(int i=0;i<N;i++) cout << A[i] << ((i == N-1) ? "\n" : " ");	
}