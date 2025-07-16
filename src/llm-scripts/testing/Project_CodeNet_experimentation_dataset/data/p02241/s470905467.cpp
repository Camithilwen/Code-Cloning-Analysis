#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<string>
#include<algorithm>
#include<functional>
#define ll long long
#define inf  999999999
#define pa pair<int,int>

using namespace std;

int n,a[200][200]={0};
void prim(){
	int d[200]={0};
	priority_queue<pair<int,pa> >  PQ; 
	pair<int,pa> q;
	pa r;
	int wei=0;
	int w=6;
	int u=w,z=0;
	d[w]=1;
	while(z!=n-1){
		for(int j=n-1;j>-1;j--){
			if(a[u][j]<=0 && d[j]==0 && u!=j) PQ.push(make_pair(a[u][j],make_pair(u,j)));
		}
	while(1){
		if(PQ.size()==0) {
			cout<<"dv"<<endl;
		break;
		}
		q=PQ.top();
		PQ.pop();
		r=q.second;
	//	cout<<"rsec"<<r.second<<endl;
		if(d[r.second]==0) break;
		
		}
	u=r.second;
//	cout<<"a" <<u<<endl;
	d[u]=1;
	wei=wei+q.first;
	z++;
//	cout<<z<<" "<<-q.first<<" "<<u<<" "<<r.first<<endl;
	
	}
	cout<<-wei<<endl;
}



int main(){
	// your code goes here
	int m;
	cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		cin>>m;
		a[i][j]=-m;
		}
	}
	prim();

	return 0;
}