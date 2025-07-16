#include <bits/stdc++.h>
#define rep(i,l,n) for(int i=l;i<n;i++)
using namespace std;

int main(){
	int l[11],v1,v2,ans;
	double x;
	while(1){
		int sum=0,y=0;
		rep(i,0,10){
			scanf("%d,",&l[i]);
			sum+=l[i];
		}
		if(scanf("%d,%d",&v1,&v2)==EOF) break;
		x=(double)sum*v1/(v1+v2);
		rep(j,0,10){
			y+=l[j];
			if(y>=x){
				ans=j+1;
				break;
			}
		}
		cout<<ans<<endl;
	}
}