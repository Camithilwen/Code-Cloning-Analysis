#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
#include<iostream>
#include<queue>
#define rep(i,a,b) for(i=a;i<b;i++)
#define F1 first.first
#define F2 first.second
#define F3 second
#define INF 2100000000
#define long long int int
using namespace std;
typedef pair<pair<int,int>,int> P1;
typedef pair<int,int> P2;
int main(void)
{
	priority_queue<P2,vector<P2>,greater<P2> > que;
	int i,j,k,n,m,x,s,e;
	int a,b,cos,tim,st,en,way;
	int leng[1001],kami[1002];
	P1 glid1[6000],glid2[6000];
	P2 tori;
	while(1) {
		cin>>n>>m;
		if(n==0&&m==0) break;
		rep(i,0,n) {
			cin>>a>>b>>cos>>tim;
			glid1[i*2].F1=a,glid1[i*2].F2=b,glid1[i*2].F3=cos;
			glid2[i*2].F1=a,glid2[i*2].F2=b,glid2[i*2].F3=tim;
			glid1[i*2+1].F1=b,glid1[i*2+1].F2=a,glid1[i*2+1].F3=cos;
			glid2[i*2+1].F1=b,glid2[i*2+1].F2=a,glid2[i*2+1].F3=tim;
		}
		sort(glid1,glid1+n*2);sort(glid2,glid2+n*2);
		kami[1]=0;
		rep(i,1,n*2) {
			if(glid1[i].F1!=glid1[i-1].F1) {
				x=glid1[i].F1;
				kami[x]=i;
			}
		}
		kami[m+1]=n*2;
		
		cin>>k;
		rep(i,0,k) {
			cin>>st>>en>>way;
			for(j=1;j<=m;j++) leng[j]=INF;
			while(!que.empty()) que.pop();
			que.push(P2(0,st));
			while(!que.empty()) {
				tori=que.top(),que.pop();
				a=tori.first,b=tori.second;
				if(a<leng[b]) {
					leng[b]=a;
					if(b==en) break;
					s=kami[b],e=kami[b+1];
					if(way==0)rep(j,s,e) que.push(P2(a+glid1[j].F3,glid1[j].F2));
					else rep(j,s,e) que.push(P2(a+glid2[j].F3,glid2[j].F2));
				}
			}
			cout<<leng[en]<<endl;
		}
	}
	return 0;
}