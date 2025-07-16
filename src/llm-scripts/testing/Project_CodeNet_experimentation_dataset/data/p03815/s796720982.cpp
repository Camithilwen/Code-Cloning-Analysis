#include<bits/stdc++.h>
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using namespace std;

int main(){
  ll x;cin>>x;
  cout<<x/11*2+(x%11>6?2:x%11>0?1:0);;
}