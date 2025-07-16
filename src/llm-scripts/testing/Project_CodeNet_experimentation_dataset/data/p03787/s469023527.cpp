#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5+5;

int N,M,K,Cnt0,Cnt1;
int Fa[MaxN],Size[MaxN],Col[MaxN];

vector<int> To[MaxN];

int Get_Fa(int x){
	return x==Fa[x]?x:Fa[x]=Get_Fa(Fa[x]);
}

bool Check(int u){
	int i,v;
	for(i=0;i<To[u].size();i++)
		if(!Col[v=To[u][i]]){
			Col[v]=3-Col[u];
			if(!Check(v))
				return false;
		}
		else if(Col[u]==Col[v])
			return false;
	return true;
}

int main(){
	int i,u,v,r1,r2;
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;i++)
		Fa[i]=i,Size[i]=1;
	while(M--){
		scanf("%d%d",&u,&v);
		To[u].push_back(v);
		To[v].push_back(u);
		if((r1=Get_Fa(u))^(r2=Get_Fa(v)))
			Fa[r1]=r2,Size[r2]+=Size[r1];
	}
	for(i=1;i<=N;i++)
		if(i==Get_Fa(i)){
			if(Size[i]<2)
				K++;
			else{
				Col[i]=1;
				Check(i)?Cnt0++:Cnt1++;
			}
		}
	printf("%lld\n",2ll*K*N-1ll*K*K+2ll*Cnt0*Cnt0+1ll*Cnt1*Cnt1+2ll*Cnt0*Cnt1);
	return 0;
}