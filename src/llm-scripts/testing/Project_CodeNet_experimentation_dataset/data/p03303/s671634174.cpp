#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;

int main()
{
   string s;cin >>s;
   string ans="";
   int w;cin >>w;
   for(int i=0;i<(int)s.size();i+=w){
     ans+=s[i];
   }
   cout <<ans << endl;
    return 0;
}
