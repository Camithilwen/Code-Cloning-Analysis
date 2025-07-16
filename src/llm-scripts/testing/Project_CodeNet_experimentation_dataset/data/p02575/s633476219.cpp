#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
int main(){
	int n,m;
	cin>>n>>m;
	map<int,int>mm;
	multiset<int>ss;
	for(int i=0;i<m;i++)mm[i]=i;
	for(int i=0;i<m;i++)ss.insert(0);
	for(int i=1,add=1;i<=n;i++){
		int a,b,c,d;
		cin>>a>>b;
		c=-1;
		for(auto j=mm.lower_bound(--a);j!=mm.end()&&j->F<=b;mm.erase(j++)){
			d=j->F;
			c=max(c,mm[d]);
			ss.erase(ss.find(d-mm[d]));
		}
		if(c+1&&b<m)mm[b]=c,ss.insert(b-c);
		if(ss.size())cout<<*ss.begin()+add<<endl,add++;
		else puts("-1");
	}
}