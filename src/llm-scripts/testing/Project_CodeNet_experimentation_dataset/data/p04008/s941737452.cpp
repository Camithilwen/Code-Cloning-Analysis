#include<bits/stdc++.h>
using namespace std;
#define maxn 100001
int n,k,he[maxn],ver[2*maxn],nxt[2*maxn],tot,cnt;
void add(int x,int y){
	ver[++tot]=y;nxt[tot]=he[x];he[x]=tot;
}
int dfs(int x,int fa){
	int maxx=0;
	for(int i=he[x];i;i=nxt[i]){
		if(ver[i]==fa)continue;
		maxx=max(maxx,dfs(ver[i],x));
	}if(x==1)return 0;
	if(maxx==k-1&&fa!=1){
		//cout<<x<<endl;
		cnt++;return 0;
	}else return maxx+1;
}
int main(){
	scanf("%d%d",&n,&k);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(i!=1)add(i,x),add(x,i);
		else if(x!=1)cnt++;
	}dfs(1,0);
	printf("%d",cnt);
}