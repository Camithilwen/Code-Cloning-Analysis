#include<bits/stdc++.h>
using namespace std;
int ff;
int n,m,col[500100],blo,tot,le,ri,ans[500100],cnt[500100];
pair<pair<int,int>,int> que[500100];
bool pp(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y){
	return x.first.second<y.first.second;
}
inline void inser(int val){cnt[val]++;if(cnt[val]==1) ff++;}
inline void eras(int val){cnt[val]--;if(cnt[val]==0) ff--;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&col[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&que[i].first.first,&que[i].first.second);
		que[i].second=i;
	}
	sort(que+1,que+m+1);
	blo=max(1,(int)(sqrt(m)));
	tot=(m+blo-1)/blo;
	for(int i=1;i<=tot;i++){
		le=blo*(i-1)+1;
		ri=min(blo*i,m);
		sort(que+le,que+ri+1,pp); 
		for(int j=1;j<=n;j++) cnt[j]=0;
		ff=0;
		for(int j=que[le].first.first;j<=que[le].first.second;j++)
			inser(col[j]);
		ans[que[le].second]=ff;
		for(int j=le+1;j<=ri;j++){
			for(int kk=que[j-1].first.first;kk<que[j].first.first;kk++)
				eras(col[kk]);
			for(int kk=que[j].first.first;kk<que[j-1].first.first;kk++)
				inser(col[kk]);
			for(int kk=que[j-1].first.second+1;kk<=que[j].first.second;kk++)
				inser(col[kk]);
			ans[que[j].second]=ff;
		}
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}
