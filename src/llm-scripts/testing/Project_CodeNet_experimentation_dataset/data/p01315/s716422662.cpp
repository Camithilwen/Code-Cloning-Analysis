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
typedef vector<long long>vll;
typedef pair<int,int> pi;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/

typedef pair<double,string> PDS;

bool my_greater(PDS a, PDS b){
  if(a.first==b.first){
    return (a.second > b.second);
  }else{
    return a.first < b.first;
  }
}

void solve(int n){
  vector<PDS> vp(n);

  string L;
  double P,A,B,C,D,E,F,S,M;
  for(int i=0;i<n;i++){
    cin>>L>>P>>A>>B>>C>>D>>E>>F>>S>>M;
    double res=(F*S*M-P)/(A+B+C+(D+E)*M);
    vp[i]=mp(res,L);
  }

  sort(all(vp),my_greater);
  reverse(all(vp));
  for(int i=0;i<n;i++){
    cout<<vp[i].second<<endl;
  }
}

int main(){
  int n;
  while(cin>>n,n){
    solve(n);
    cout<<"#"<<endl;
  }
  return 0;
}

