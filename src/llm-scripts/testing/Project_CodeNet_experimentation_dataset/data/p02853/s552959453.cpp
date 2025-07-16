#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
int main(){
  ll A,B;
  cin>>A>>B;
  if(A==1 && B==1){cout<<1000000<<endl;}
  else{cout<<max((ll)0,100000*(4-A))+max((ll)0,100000*(4-B))<<endl;}
}