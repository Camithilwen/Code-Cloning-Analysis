#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define dbg(x) cout<<#x"="<<x<<endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

#define INF 1000000000
#define DAYS 100

int main(){
  int date[DAYS];

  while(true){
    int n,q;
    cin >> n >> q;
    if(n==0 && q==0) break;

    rep(i,DAYS) date[i]=0;

    rep(i,n){
      int m;
      scanf("%d",&m);
      rep(j,m){
	int d;
	scanf("%d", &d);
	date[d-1]++;
      }
    }

    int res=0, resN=q-1;
    rep(i,DAYS){
      if(date[i]>resN){
	res=i+1;
	resN=date[i];
      }
    }

    cout << res << endl;

  }

}