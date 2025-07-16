#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<string>

using namespace std;

#define rep(i,n) for(int i=0;i<int(n);i++)
#define reps(i,n) for(int i=1;i<=int(n);i++)
#define sint(i) scanf("%d",&i);
#define sintt(i,j) scanf("%d%d",&i,&j);
#define sinttt(i,j,k) scanf("%d%d%d",&i,&j,&k);
#define sintttt(i,j,k,m) scanf("%d%d%d%d",&i,&j,&k,&m);

#define INF 1010000000
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

class S{
	public:
	int p,n;
	S(int p,int n):p(p),n(n){}
	
	bool operator<(const S& a)const{
		return n>a.n;
	}
};

////////////djk//////////////////////////////////////////
int main(){
	while(1){
		int n,m;
		sintt(n,m);
		if(n==0)break;
		vector<pair<int,int> > load[101];
		
		rep(o,m){
			int a;
			sint(a);
			if(a==1){
				int b,c,d;
				sinttt(b,c,d);
				load[b].push_back(make_pair(c,d));
				load[c].push_back(make_pair(b,d));
			}else{
				int s,g;
				sintt(s,g);
				
				priority_queue<S> que;
				que.push(S(s,0));
				
				int visit[101];
				rep(i,101)visit[i]=0;
				
				int ans=-1;
			
				while(1){
					if(que.empty()==1){
						break;
					}
					
					S u=que.top();
					que.pop();
					
					if(visit[u.p]==1){
						continue;
					}
					visit[u.p]=1;
					
					if(u.p==g){
						ans=u.n;
						break;
					}
					
					rep(i,load[u.p].size()){
						que.push( S( load[u.p][i].first,  u.n+load[u.p][i].second));
					}
				}
				printf("%d\n",ans);
			}
		}
	}
}