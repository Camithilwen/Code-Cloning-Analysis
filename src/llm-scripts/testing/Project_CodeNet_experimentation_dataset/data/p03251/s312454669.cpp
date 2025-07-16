#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	vector<int> a(n),b(m);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for(int i=0;i<101;i++){
		if(a[n-1]<i && i<=b[0] && i>x && i<y){
			cout<<"No War";
			return 0;
		}
	}
	cout<<"War";
}