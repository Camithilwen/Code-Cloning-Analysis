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
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  string S;
  cin>>S;
  map<char, int> amap;
  bool can = false;
  if(S.size()!=26) {
    can = true;
    for(int i=0;i<S.size();++i) {
      amap[S[i]]++;
    }
    for(char a='a';a<='z';++a) {
      if(amap[a]==0) {
        S.push_back(a);
        break;
      }
    }
  }
  else {
    vector<char> arr;
    arr.push_back(S[25]);
    for(int i=24;i>=0;--i) {
      for(int j=0;j<arr.size();++j) {
        if(arr[j]>S[i]) {
          can = true;
          S[i] = arr[j];
          for(int j=0;j<25-i;++j) S.pop_back();
          break;
        }
      }
      if(can) break;
      arr.push_back(S[i]);
      sort(arr.begin(), arr.end());
    }
  }
  if(can) cout<<S<<endl;
  else cout<<-1<<endl;
}

