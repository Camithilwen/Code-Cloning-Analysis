#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rall(x) (x).rbegin(),(x).rend()

int main(){
	int n; cin>>n;
	n*=2;
	vector<int> v(n);
	rep(i,n) cin>>v[i];
	sort(rall(v));
	int cnt=0;
	for(int i=0; i<n; i+=2){
		cnt+=v[i+1];
	}
	cout<<cnt<<endl;
}