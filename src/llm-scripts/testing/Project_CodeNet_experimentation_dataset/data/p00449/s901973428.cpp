#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int dis[110][110];
const int INF=100100100/3;

int main() {
	int n,k;
	int a,b,c,d,e;
	int x,y;
	while(cin>>n>>k,n){
		for(x=0;x<n;x++){
			for(y=0;y<n;y++){
				dis[x][y]=(x==y?0:INF);
			}
		}
		while(k--){
			if(in()==1){
				cin>>c>>d>>e;
				c--;d--;
				chmin(dis[c][d],e);
				chmin(dis[d][c],e);
				for(x=0;x<n;x++){
					for(y=0;y<n;y++){
						chmin(dis[x][y],dis[x][c]+dis[c][d]+dis[d][y]);
						chmin(dis[x][y],dis[x][d]+dis[d][c]+dis[c][y]);
					}
				}
			}else{
				cin>>a>>b;
				a--;b--;
				if(dis[a][b]==INF){
					cout<<-1<<endl;
				}else{
					cout<<dis[a][b]<<endl;
				}
			}
		}
	}
	return 0;
}