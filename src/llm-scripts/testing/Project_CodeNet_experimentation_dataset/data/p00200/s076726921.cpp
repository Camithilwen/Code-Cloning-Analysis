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
vector<vector<char> >tmp;
vector<vector<int> >scr;
int main(){
	int n,m;
	while(cin>>n>>m,n||m){
		vector<int>d(m);
		vector<vi >cost(m,vector<int>(m));
		vector<vi >tim(m,vector<int>(m));
		vector<bool>used(m);
		rep(i,m)rep(j,m){cost[i][j]=inf;tim[i][j]=inf;}
		rep(i,n){
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			a--;b--;
			cost[a][b]=cost[b][a]=c;
			tim[a][b]=tim[b][a]=d;
		}
		cin>>n;
		rep(i,n){
			int a,b,c;
			cin>>a>>b>>c;
			a--;b--;
			rep(j,m)d[j]=inf;
			rep(j,m)used[j]=false;
			if(c){
				d[a]=0;
				while(1){
					int v=-1;
					rep(j,m)if(!used[j]&&(v==-1||d[v]>d[j]))v=j;
					if(v==-1)break;
					used[v]=true;
					rep(j,m)d[j]=min(d[j],d[v]+tim[v][j]);
				}
			}else{
				d[a]=0;
				while(1){
					int v=-1;
					rep(j,m)if(!used[j]&&(v==-1||d[v]>d[j]))v=j;
					if(v==-1)break;
					used[v]=true;
					rep(j,m)d[j]=min(d[j],d[v]+cost[v][j]);
				}
			}
			cout<<d[b]<<endl;
		}
	}
}