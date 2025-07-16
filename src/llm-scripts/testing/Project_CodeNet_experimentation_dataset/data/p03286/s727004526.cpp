#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  ll N;
  cin >> N;
  if (N == 0){
    cout << '0' << endl;
    exit(0);
  }
  
  vector<ll> bin(0);
  while (N != 1){
    ll amari = N % -2;
    if (amari >= 0){
      bin.push_back(amari);
      N /= -2;
    }
    else{
      bin.push_back(1);
      N /= -2;
      N += 1;
    }
  }
  bin.push_back(1);
  
  for (ll i = bin.size() - 1; i >= 0; i--){
    ll a = bin.at(i);
    cout << a;
  }
  cout << endl;
  
  /*ll a = N % -2;
  ll b = N / -2;
  cout << a << ' ' << b << endl;*/
}