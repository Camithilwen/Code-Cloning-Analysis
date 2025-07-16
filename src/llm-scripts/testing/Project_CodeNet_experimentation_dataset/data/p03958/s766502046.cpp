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
  int K, T;
  cin>>K>>T;
  int tmp;
  priority_queue<pair<int, int> > que;
  for(int i=0;i<T;++i) {
    cin>>tmp;
    que.push(mp(tmp, i));
  }
  pair<int, int> tmp1, tmp2;
  int bef = -1;
  int ans = 0;
  for(int i=0;i<K;++i) {
    if(que.size()==1) {
      tmp1 = que.top();que.pop();
      if(bef==tmp1.se) ans++;
      tmp1.fi--;
      bef = tmp1.se;
      if(tmp1.fi>0) que.push(tmp1);
    }
    else {
      tmp1 = que.top();que.pop();
      tmp2 = que.top();que.pop();
      if(bef==tmp1.se) {
        tmp2.fi--;
        bef = tmp2.se;
      }
      else {
        tmp1.fi--;
        bef = tmp1.se;
      }
      if(tmp1.fi>0) que.push(tmp1);
      if(tmp2.fi>0) que.push(tmp2);
    }
  }
  cout<<ans<<endl;
}

