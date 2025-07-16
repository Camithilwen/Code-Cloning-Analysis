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
  string S;
  cin>>S;
  map<char, int> amap;
  for(int i=0;i<S.size();++i) {
    amap[S[i]]++;
  }
  char ans = 'A';
  for(char a='a';a<='z';++a) {
    if(amap[a]==0) {
      ans = a;
      break;
    }
  }
  if(ans=='A') cout<<"None"<<endl;
  else cout<<ans<<endl;
}

