#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
	while(b){
		a %= b;
		swap(a, b);
	}
	return a;
}
int who_wins(vector<int> a){
	int q[2] = {};
	for(int v : a) q[v % 2]++;
	if(q[0]%2){
		return 1;
	}
	if(q[1] > 1){
		return 2;
	}
	for(int &v : a) if(v%2){
		if(v == 1) return 2;
		v--;
	}
	int g = 0;
	for(int v : a) g = gcd(g, v);
	for(int & v : a) v /= g;
	return 3 - who_wins(a);
}
int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	if(who_wins(a) == 1) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}
