#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	for(int i=n; i>0; i--){
		double r=sqrt(i);
		if(r==(int)r) {cout<<i<<endl; return 0;}
	}
}