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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  string S;
  cin>>S;
  map<char, int> amap;
  for(int i=0;i<S.size();++i) {
    amap[S[i]]++;
  }
  if(S.size()<26) {
    for(char i='a';i<='z';++i) {
      if(amap[i]==0) {
        S.push_back(i);
        break;
      }
    }
    cout<<S<<endl;
    return 0;
  }
  else {
    int num;
    bool can = false;
    vector<char> arr;
    arr.push_back(S[S.size()-1]);
    for(int i=S.size()-2;i>=0;--i) {
      for(int j=0;j<arr.size();++j) {
        if(S[i]<arr[j]) {
          can = true;
          num = S.size()-i;
          S[i] = arr[j];
          break;
        }
      }
      if(can) break;
      arr.push_back(S[i]);
      sort(arr.begin(), arr.end());
    }
    if(!can) {
      cout<<-1<<endl;
      return 0;
    }
    for(int i=0;i<num-1;++i) S.pop_back();
    cout<<S<<endl;
    return 0;
  }
}

