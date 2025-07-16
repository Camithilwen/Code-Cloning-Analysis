#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll>P;

int main(){
  ll N;
  cin>>N;
  vector<P>Sup;
  vector<P>Sdown;
  rep(i,N){
  	string s;
  	cin>>s;
    ll total=0,mini=0;
    rep(j,s.size()){
      if(s[j]=='('){total++;}
      else{total--;}
      mini=min(mini,total);
    }
    if(total>=0){Sup.push_back(P(mini,total));}
    else{Sdown.push_back(P(mini-total,-total));}
  }
  sort(Sup.begin(),Sup.end());
  reverse(Sup.begin(),Sup.end());
  
  sort(Sdown.begin(),Sdown.end());
  reverse(Sdown.begin(),Sdown.end());
  
  int flag=0;
  ll sum1=0;
  ll sum2=0;
  rep(i,Sup.size()){
  	if(Sup[i].first<0&&sum1+Sup[i].first<0){flag=1;}
  	else{sum1+=Sup[i].second;}
    if(sum1<0){flag=1;}
  }
  rep(i,Sdown.size()){
  	if(Sdown[i].first<0&&sum2+Sdown[i].first<0){flag=1;}
  	else{sum2+=Sdown[i].second;}
    if(sum2<0){flag=1;}
  }
  if(sum1!=sum2){flag=1;}
  if(flag==1){cout<<"No";}
  if(flag==0){cout<<"Yes";}
}
