#include<bits/stdc++.h>
using namespace std;

#define ll long long
//~ #define endl '\n'

void solve(){
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	for(int i = 0; i<3; i++){
		if(a[i] == a[(i + 1)%3] && a[i] != a[(i + 2)%3]){
			cout<<"Yes"<<endl;
			return;
		}
	}
	cout<<"No"<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
