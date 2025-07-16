#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long 

int main() {
  ll a,b;
  cin >> a  >> b;
  
  vector<ll> ay;
  vector<ll> by;
  
  for(ll i = 1; i <= sqrt(a);i++){
    if(a%i == 0){
      ay.push_back(i);
      if(i != a/i){
        ay.push_back(a/i);
      }
    }
  }
  for(ll i = 1; i <= sqrt(b);i++){
    if(b%i == 0){
      by.push_back(i);
      if(i != b/i){
        by.push_back(b/i);
      }
    }
  }
  //cout << ay.size() << " " << by.size() << endl;
  vector<ll> kys;
  for(int i = 0;i<ay.size();i++){
    for(int j = 0;j<by.size();j++){
      
      if(ay[i]==by[j]){
        kys.push_back(ay[i]);
        //cout << ay[i] << " " << by[j]<< endl;
      }
    }  
  }    
  
  int res = 0;
  int flg = 0;
  sort(kys.begin(),kys.end(),greater<ll>());
  for(int i = 0;i<kys.size();i++){
    flg = 0;
    for(int j = i+1;j<kys.size();j++){
      if(__gcd(kys[i],kys[j]) != 1){
        flg = 1;
        break;
      } 
    }
    if(flg == 0){res++;}
  }
  
  
  cout << res;
}