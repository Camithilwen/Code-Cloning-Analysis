#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000


int main(){
	
	int A,B,M;
	cin>>A>>B>>M;
	
	vector<int> a(A),b(B);
	
	for(int i=0;i<A;i++)cin>>a[i];
	for(int i=0;i<B;i++)cin>>b[i];
	
	int ans = 1000000;
	
	for(int i=0;i<M;i++){
		int x,y,c;
		cin>>x>>y>>c;
		x--;y--;
		
		ans = min(ans,a[x]+b[y]-c);
	}
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
	ans = min(ans,a[0]+b[0]);
	
	cout<<ans<<endl;
	
	return 0;
}