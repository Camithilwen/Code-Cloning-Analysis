#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
pair<int,int> p[maxn];
int n;
int L1,R1,L2,R2;
int L[maxn],R[maxn];

void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&p[i].first,&p[i].second);
    }
    sort(p+1,p+n+1);

    L1=p[1].first;R1=p[1].second;
    L[n]=p[n].first;R[n]=p[n].second;

    for(int i=n-1;i>1;--i){
        R[i]=min(R[i+1],p[i].second);
        L[i]=max(L[i+1],p[i].first);
    }
    int ans=max(R1-L1+1,0)+max(R[2]-L[2]+1,0),res=0;
    for(int i=3;i<=n;++i){
        L1=max(L1,p[i-1].first);
        R1=min(R1,p[i-1].second);
        ans=max(max(R1-L1+1,0)+max(R[i]-L[i]+1,0),ans);
    }
    for(int i=1;i<=n;++i)res=max(res,p[i].second-p[i].first+1);
	int maxl=INT_MIN,minr=INT_MAX;
	for(int i=1;i<=n;++i){
		maxl=max(maxl,p[i].first);
		minr=min(minr,p[i].second);
	}
	res+=max(0,minr-maxl+1);
    printf("%d\n",max(ans,res));
}
int main(){
    solve();

    return 0;
}