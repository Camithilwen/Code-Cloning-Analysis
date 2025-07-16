#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct edge{
	int from,to,weight;
};

bool asc(const edge &e,const edge &f){
	return e.weight < f.weight;
}

int init(vector<int> &U){
	for (int i=0;i<U.size();i++){
		U[i]=i;
	}
}

int root(vector<int> &U,int x){
	if(x==U[x]){
		return x;
	}else{
		return U[x]=root(U,U[x]);
	}
}

void unite(vector<int> &U,int x,int y){
	int px=root(U,x);
	int py=root(U,y);
	U[px]=py;
}

bool same(vector<int> &U,int x,int y){
	return root(U,x)==root(U,y);
}

int main(){
	int V,E,s,t,w;
	cin >> V >> E;
	
	vector<int> U(V);
	init(U);
	
	vector<edge> EdgeList(E);
	
	for (int i=0;i<E;i++){
		edge e;
		cin >> e.from >> e.to >> e.weight;
		EdgeList[i]=e;
	}
	
	sort(EdgeList.begin(),EdgeList.end(),asc);
	
	int W=0;
	
	for (int i=0;i<E;i++){
		edge e=EdgeList[i];
		if(same(U,e.from,e.to)){
			continue;
		}else{
			unite(U,e.from,e.to);
			W+=e.weight;
		}
	}
	
	cout << W << endl;
	
	return 0;
}