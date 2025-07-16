#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d,e,f,ans=0,k,g;
	cin>>a>>b>>c>>d>>e>>f;
	k=min(min(a,b),min(c,d));
	g=min(e,f);
	ans=a+b+c+d+e+f-k-g;
	cout<<ans<<endl;
}
