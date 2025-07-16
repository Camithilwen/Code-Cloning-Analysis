#include <bits/stdc++.h>
#define rep(i,l,n) for(int i=l;i<n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
using namespace std;

int main(){
	int n,q;
	while(1){
		pair<int,int> data[101]={};
		rep(i,0,101){
			data[i].second=-i;
		}
		cin>>n>>q;
		if(n==0 && q==0) break;
		rep(i,0,n){
			int m,d;
			cin>>m;
			rep(j,0,m){
				cin>>d;
				data[d].first++;
			}
		}
		sort(data,data+101);
		reverse(data,data+101);
		if(data[0].first<q) cout<<0<<endl;
		else cout<<-data[0].second<<endl;
	}
}

/*for(map<int,int>::iterator it=dat.begin();it!=dat.end();it++)
	if(it->second>Max){
		max=it->second;
		ans=it->first;
	}*/