#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<time.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
const int inf=1e8;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
int main(){
	int n,m;
	while(cin>>n>>m,n+m){
		vi in(n+1);
		rep(i,n)cin>>in[i+1];
		vi cro;
		rep(i,n+1)rep(j,n+1)cro.pb(in[i]+in[j]);
		
		sort(all(cro));
		
		int out=0;
		rep(i,cro.size()){
			int d=m-cro[i];
			int h=cro.size();
			int l=0;
			while(1){
				if(h-l==1)break;
				int t=(h+l)/2;
				if(cro[t]>d)h=t;
				else l=t;
			}
			if(cro[i]+cro[l]<=m)out=max(out,cro[i]+cro[l]);
		}
		cout<<out<<endl;
	}
}