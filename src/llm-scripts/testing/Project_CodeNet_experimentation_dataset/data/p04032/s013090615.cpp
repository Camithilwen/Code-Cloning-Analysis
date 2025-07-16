// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,n,maxi=0,f=0,mini=INF,sum=0;
    string str;
    cin>>str;
    if(str.length()==2&&str[0]==str[1]) {
      cout<<1<<" "<<2<<endl;
      return 0;
    }
    rep(i,str.length()-2){
      if(str[i]==str[i+1]){
        cout<<i+1<<" "<<i+3<<endl;
        return 0;
      }if(str[i]==str[i+2]){
        cout<<i+1<<" "<<i+3<<endl;
        return 0;
      }
    }
    if(str[str.length()-2]==str[str.length()-1]) {
      cout<<str.length()-2<<" "<<str.length()<<endl;
      return 0;
    }
    cout<<-1<<" "<<-1<<endl;
    
}
