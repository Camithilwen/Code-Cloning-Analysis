#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <functional>
#include <math.h>
#include <utility>
using namespace std;
typedef pair<int,int> P;
int n,rnk[101];
P p[100];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		p[i].first=0;
		p[i].second=i+1;
	}
	for(int i=0;i<n*(n-1)/2;i++){
		int a,b,c,d;cin>>a>>b>>c>>d;a--;b--;
		if(c!=d){
			p[c>d?a:b].first+=3;
		}else{
			p[a].first+=1;
			p[b].first+=1;
		}
	}
	sort(p,p+n,greater<P>());
	for(int i=1;i<=n;i++){
		int r=i;
		if(i!=1&&p[i-1].first==p[i-2].first)r=rnk[p[i-2].second];
		rnk[p[i-1].second]=r;
	}
	for(int i=1;i<=n;i++){
		cout<<rnk[i]<<endl;
	}
}