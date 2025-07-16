#include <bits/stdc++.h>
using namespace std;
int mi=(-1000000);

int main() {
	int k,x; cin >> k >> x;
	if(x-k+1<mi) {
		for(int i=mi;i<mi+k;i++) cout << i;
		cout << endl;
		return 0;
	}
	for(int i=x-k+1;i<x+k;i++) cout << i << ' ';
	cout << endl;
}