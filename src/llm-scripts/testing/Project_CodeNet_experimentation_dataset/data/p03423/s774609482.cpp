#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	vector<int> v(1001);
	int cnt=0;
	for(int i=1; i<1002; i++){
		if(i%3==0) cnt++;
		v[i]=cnt;
	}
	int n; cin>>n;
	cout<<v[n]<<endl;
}