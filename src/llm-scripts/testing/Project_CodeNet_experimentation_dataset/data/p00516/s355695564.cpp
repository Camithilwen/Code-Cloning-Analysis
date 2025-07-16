#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;

typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;

const int INF=1<<29;
const double EPS=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int vote[1010];
int cost[1010];

int main(){
	int n,m;
	cin>>n>>m;
	memset(vote, 0, sizeof(vote));
	memset(cost, 0, sizeof(cost));
	rep(i, n){
		cin>>cost[i];
	}
	rep(i, m){
		int x;
		cin>>x;
		rep(j, n){
			if(cost[j]<=x){
				vote[j]++;
				break;
			}
		}
	}
	int cnt = 0;
	int ans = 0;
	rep(i, n){
		if(vote[i]>=cnt){
			cnt =vote[i];
			ans=i;
		}
	}
	cout <<ans+1<<endl;
	return 0;
}