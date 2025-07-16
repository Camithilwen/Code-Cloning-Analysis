#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, m;

int main(void){
	cin >> n >> m;
	vector<bool> ac(n+1);
	vector<lli> wa(n+1);
	rep(i, m){
		int p;
		string s;
		cin >> p >> s;
		if(s == "AC") ac[p] = true;
		else{
			if(!ac[p]) wa[p]++;
		}
	}
	lli sumac = 0, sumwa = 0;
	rep(i, n+1){
		if(ac[i]){
			sumac++;
			sumwa+=wa[i];
		}
	}
	cout << sumac << " " << sumwa << endl;
	return 0;
}
