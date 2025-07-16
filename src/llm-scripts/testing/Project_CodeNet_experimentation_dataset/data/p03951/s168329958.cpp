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
  int N;
  cin>>N;
  string S, T;
  cin>>S>>T;
  int num = 0;
  bool can;
  for(int i=0;i<N;++i) {
    can = true;
    for(int j=0;j<N-i;++j) {
      if(S[i+j]!=T[j]) can = false;
    }
    if(can) {
      num = N-i;
      break;
    }
  }
  cout<<2*N-num<<endl;
}
