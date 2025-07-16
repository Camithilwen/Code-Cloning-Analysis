#include<bits/stdc++.h>
using namespace std;
const int N=305;
#define fi first
#define se second
typedef pair<int,int>P;
priority_queue<P>que;
int n,m,b[N],vi[N],cnt[N],a[N][N];
bool check(int mid){
	while(!que.empty())	que.pop();
	for(int i=1;i<=m;i++)	b[i]=0;
	for(int i=1;i<=n;i++)	++b[a[i][cnt[i]=1]];
	for(int i=1;i<=m;i++)	vi[i]=0,que.push(P(b[i],i));
	while(!que.empty()){
		P x=que.top();	que.pop();
		if(vi[x.se])	continue;
		if(x.fi<=mid)	return true;

		vi[x.se]=1;
		for(int i=1;i<=n;i++){
			if(a[i][cnt[i]]!=x.se)	continue;
			while(vi[a[i][cnt[i]]]&&cnt[i]<=m)	++cnt[i];
			if(cnt[i]>m)	return false;
			que.push(P(++b[a[i][cnt[i]]],a[i][cnt[i]]));
		}
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))	r=mid;
		else	l=++mid;
	}
	printf("%d\n",l);
	return 0;
}
