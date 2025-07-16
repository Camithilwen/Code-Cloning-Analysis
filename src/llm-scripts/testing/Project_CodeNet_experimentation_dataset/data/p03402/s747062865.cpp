#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=200010;
const ll mod=1e9+7;


int main(){
  int a,b;
  cin >> a >> b;
  vector<vector<char>> data(100, vector<char>(100,'.'));
  rep(i,50)rep(j,100){ data[i][j]='#'; }
  int cnt=a-1;
  rep(i,25)rep(j,50)if(cnt){ data[i*2][j*2]='.'; cnt--;}
  cnt=b-1;
  rep(i,25)rep(j,50)if(cnt){ data[51+i*2][j*2]='#'; cnt--;}

  cout << 100 << " " << 100 << endl;
  rep(i,100){ rep(j,100){ cout << data[i][j]; }  cout<<endl; }
  return 0;
}