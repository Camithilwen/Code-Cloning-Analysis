#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
using  P=pair<ll,ll>;
int main(){
  ll counte=0,countw=0;
  string str;
  cin>>str>>str;
  vector<ll> w((ll)str.size());
  vector<ll> e((ll)str.size());
  for(ll i=0;i<(ll)str.size();i++){
    if(i==0){
      if(str.at(i)=='E'){e.at(i)=1;w.at(i)=0;counte++;}
      else{e.at(i)=0;w.at(i)=1;countw++;}
    }
    else{
      if(str.at(i)=='E'){e.at(i)=e.at(i-1)+1;w.at(i)=w.at(i-1);counte++;}
      else{e.at(i)=e.at(i-1);w.at(i)=w.at(i-1)+1;countw++;}
    }
  }
  ll ans;
  for(ll i=0;i<(ll)str.size();i++){
    if(i==0){ans=counte-e.at(0);}
    else if(i==(ll)str.size()-1){ans=min(ans,w.at(i));}
    else{ans=min(ans,w.at(i-1)+counte-e.at(i));}
  }
  cout<<ans<<endl;
}