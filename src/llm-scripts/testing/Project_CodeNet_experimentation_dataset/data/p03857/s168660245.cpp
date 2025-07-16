#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <numeric>
#include <iomanip>
using namespace std;
//
const int inf=1e9+7;//0x3f
//
struct UnionFind{
	//
	vector<int> par,ran;
	//
	UnionFind(int n){
		init(n);
	}
	//
	void init(int n){
		par.resize(n);
		ran.resize(n,0);
		for(int i=0;i<n;i++){
			par[i]=i;
		}
	}
	//
	int find(int x){
		return (x==par[x]?x:par[x]=find(par[x]));
	}
	//
	bool same(int x,int y){
		return find(x)==find(y);
	}
	//
	void unite(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y){
			return;
		}else{
			if(ran[x]<ran[y]){
				par[x]=y;
			}else{
				par[y]=x;
				if(ran[x]==ran[y]){
					ran[x]++;
				}
			}
		}
	}
	//
};
//
int main(){
	int N,K,L;
	cin>>N>>K>>L;
	UnionFind road(N),train(N);
	for(int i=0;i<K;i++){
		int p,q;
		cin>>p>>q;
		p--;q--;
		road.unite(p,q);
	}
	for(int i=0;i<L;i++){
		int r,s;
		cin>>r>>s;
		r--;s--;
		train.unite(r,s);
	}
	int r[200000],t[200000];
	for(int i=0;i<N;i++){
		r[i]=road.find(i);
		t[i]=train.find(i);
	}
	map<pair<int,int>,int> M;
	for(int i=0;i<N;i++){
		M[make_pair(r[i],t[i])]++;
	}
	for(int i=0;i<N;i++){
		if(i){
			cout<<" ";
		}
		cout<<M[make_pair(r[i],t[i])];
	}
	cout<<endl;
	return 0;
}