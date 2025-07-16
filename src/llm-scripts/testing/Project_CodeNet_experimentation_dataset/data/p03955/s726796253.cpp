#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int n,id[maxn],omove,orev,emove,erev,bit[maxn],rnk[maxn];
bool rev[maxn],vis[maxn];

inline void wrong(){
	puts("No");
	exit(0);
}
inline void add(int x,int val){
	while(x<maxn){
		bit[x]+=val;
		x+=x&-x;
	}
}
inline int sum(int x){
	int res=0;
	while(x){
		res+=bit[x];
		x-=x&-x;
	}
	return res;
}

int main(){
	cin>>n;
	for(int i=1,a;i<=n;++i){
		cin>>a;
		id[i]=(a+2)/3;
		rnk[id[i]]=i;
		if(vis[id[i]]||a==3*id[i]-1)
			wrong();
		vis[id[i]]=true;
		if(a==3*id[i])
			rev[i]=true;
	}
	for(int i=1,a;i<=n;++i){
		cin>>a;
		if(a!=3*id[i]-1)
			wrong();
	}
	for(int i=1,a;i<=n;++i){
		cin>>a;
		if(rev[i]&&a!=3*id[i]-2||!rev[i]&&a!=3*id[i])
			wrong();
	}
	for(int i=1;i<=n;++i)
		if((i&1)!=(id[i]&1))
			wrong();
	for(int i=1;i<=n;i+=2)
		add(i,1);
	for(int i=1;i<=n;i+=2){
		add(rnk[i],-1);
		omove+=sum(rnk[i]);
		orev+=rev[i];
	}
	memset(bit,0,sizeof(bit));
	for(int i=2;i<=n;i+=2)
		add(i,1);
	for(int i=2;i<=n;i+=2){
		add(rnk[i],-1);
		emove+=sum(rnk[i]);
		erev+=rev[i];
	}
	if((omove&1)!=(erev&1)||(emove&1)!=(orev&1))
		wrong();
	puts("Yes");
	return 0;
}