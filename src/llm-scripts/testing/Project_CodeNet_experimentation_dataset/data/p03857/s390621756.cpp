#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int f1[N],f2[N];
map <pair <int ,int > ,int > ans;
inline int getrt(int x,int *f){
	return f[x]==x?x:f[x]=getrt(f[x],f);
}
inline void merge(int x,int y,int*f){
	if (getrt(x,f)!=getrt(y,f))
		f[getrt(x,f)]=y;
}
int main (){
	int n,m,k;scanf ("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) f1[i]=f2[i]=i;
	for (int i=1,u,v;i<=m;i++)
		scanf ("%d%d",&u,&v),merge(u,v,f1);
	for (int i=1,u,v;i<=k;i++)
		scanf ("%d%d",&u,&v),merge(u,v,f2);
	for (int i=1;i<=n;i++)
		ans[make_pair(getrt(i,f1),getrt(i,f2))]++;
	for (int i=1;i<=n;i++)
		printf ("%d ",ans[make_pair(getrt(i,f1),getrt(i,f2))]);
	return 0;
}
