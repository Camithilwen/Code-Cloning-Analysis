//Δ_E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1<<20;
const int MO = 1e9+7;
int n,m,a[N],b[N],s[N];
vector<int> v[N];
int cal(int o,int f=0){
	int i,j,x,y;
	x=1,y=0;
	for(i=0;i<v[o].size();i=i+1){
		j=v[o][i];
		y=(y+x)%MO;
		if(i+1<v[o].size())
			x=(x+(LL)y*(s[v[o][i+1]]-s[j])%MO)%MO;
	}
	if(f)
		return x;
	return y;
}
int main()
{
	int i,x,o;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		m^=a[i];
		b[i]=b[i-1]^a[i];
		s[i]=s[i-1];
		if(!b[i])
			s[i]++;
	}
	for(i=1;i<n;i=i+1)
		v[b[i]].push_back(i);
	if(m){
		v[m].push_back(n);
		cout<<cal(m,1);
		return 0;
	}
	x=0;
	for(i=1;i<N;i=i+1)
		x=(x+cal(i))%MO;
	o=1;
	for(i=1;i<=s[n-1];i=i+1)
		o=o*2%MO;
	cout<<(x+o)%MO;
	return 0;
}