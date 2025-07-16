#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pi 3.14159265359
#define all(i) i.begin(),i.end()
using namespace std;
const long long INF=1e9+7;
const string alp="abcdefghijklmnopqrstuvwxyz"; //26
const string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=998244353LL;
//const ll MOD=1777777777LL;


int main() {
  string s;
  cin>>s;
  ll count=0;
  bool judge=false;
  for(int i=2;i<s.size()-1;i++){
    if(s[i]=='C'){
      count++;
    }
  }
  if(count==1) judge=true;
  if(s[0]!='A'){
    judge=false;
  }
  for(int i=0;i<s.size();i++){
    for(int j=0;j<26;j++){
      if(s[i]!='A'&&s[i]!='C'&&s[i]==ALP[j]){
        judge=false;
      }
    }
  }
  if(judge) cout<<"AC"<<endl;
  else cout<<"WA"<<endl;
}
