#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int c[2][600][600];
int D[2];
int N;
vector<P> ds;
void dfs(int t[600][600],int i, int j, int v){
	if(t[i][j]>=0)return;
	t[i][j]=v;
	for(P d:ds){
		int x=i+d.first;
		int y=j+d.second;
		if(0<=x&&x<2*N&&
			0<=y&&y<2*N){
			dfs(t,x,y,v^1);
		}
	}
}
int main() {
	cin >> N >> D[0] >> D[1];
	memset(c,-1,sizeof(c));
	for(int i=0;i<2;i++){
		ds.clear();
		for(int k=0;k*k<=D[i];k++){
			int v=(int)(sqrt(D[i]-k*k)+0.5);
			if(v*v+k*k==D[i]){
				//cerr << k << ", " << v << endl;
				ds.push_back(P(k,v));
				ds.push_back(P(k,-v));
				ds.push_back(P(-k,v));
				ds.push_back(P(-k,-v));
			}
		}
		for(int x=0;x<2*N;x++){
			for(int y=0;y<2*N;y++){
				if(c[i][x][y]==-1){
					dfs(c[i],x,y,0);
				}
				//cerr << c[i][x][y];
			}
			//cerr << endl;
		}
		//cerr << endl;
	}
	vector<P> ret[2][2];
	for(int x=0;x<2*N;x++){
		for(int y=0;y<2*N;y++){
			auto& r=ret[c[0][x][y]][c[1][x][y]];
			r.push_back(P(x,y));
			if(r.size()==N*N){
				for(auto p:r){
					cout << p.first << " " << p.second << endl;
				}
				return 0;
			}
		}
	}

	return 0;
}

