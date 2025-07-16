#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <list>
#include <numeric>
#include <utility>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <cassert>

#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/

void solve(int n,int m){
  int a,b;
  bool p[n+5][n+5],ans[n+5];
  rep(i,n+5)rep(j,n+5){p[i][j]=ans[j]=false;}
  rep(i,m){
    cin>>a>>b;
    p[a][b]=p[b][a]=true;
  }
  REP(i,1,n+1){
    REP(j,1,n+1){
      ans[i]+=p[1][i];
      if(p[1][i]==true&&p[i][j]==true)ans[j]=true;
    }
  }
  int cnt=0;
  REP(i,2,n+1)cnt+=ans[i];
  cout<<cnt<<endl;
}

int main(){
  int n,m;
  while(cin>>n>>m){
    if(n==0&&m==0)break;
    solve(n,m);
  }
  
  return 0;
}

