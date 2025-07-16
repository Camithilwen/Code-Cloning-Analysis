#include<bits/stdc++.h>
using namespace std;

long long N;
long long A[200005];
int main(){
	cin >> N;
	for(long long i = 0; i < N; i++) {
		cin >> A[i];
	}
	set<long long> aset;
	for(long long i = 0; i < N; i++) {
		if(aset.count(A[i]) != 0) {
			cout << "NO" << endl;
			return 0;
		}
		aset.insert(A[i]);
	}
	cout << "YES" << endl;
}