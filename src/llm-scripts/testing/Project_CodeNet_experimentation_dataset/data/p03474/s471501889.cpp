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
  int A, B;
  cin>>A>>B;
  string S;
  cin>>S;
  string tmp1=S.substr(0, A), tmp2=S.substr(A+1, B);
  bool can = true;
  for(int i=0;i<tmp1.size();++i) {
    if(tmp1[i]=='-') can = false;
  }
  if(S[A]!='-') can = false;
  for(int i=0;i<tmp2.size();++i) {
    if(tmp2[i]=='-') can = false;
  }
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

