#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, L;
  cin>>N>>L;
  int ans = 0;
  if(L*(L+N-1)<=0) {
    for(int i=L;i<=L+N-1;++i) {
      ans += i;
    }
  }
  else if(L+N-1<0) {
    for(int i=L;i<L+N-1;++i) ans += i;
  }
  else {
    for(int i=L+1;i<=L+N-1;++i) ans += i;
  }
  cout<<ans<<endl;
}

