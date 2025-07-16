#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;

int main(){ 
  int N,M; cin >> N >> M;
  
  vector<ll> A(N),B(M);
  
  map<ll,ll> mA,mB;
  
  for(int i = 0; i < N; i++){ cin >> A[i]; mA[A[i]]++;}
  for(int j = 0; j < M; j++){ cin >> B[j]; mB[B[j]]++;}
  
  for(auto ne : mA){ if(ne.second>=2){ cout<< 0 << endl; return 0;}}
  for(auto ne : mB){ if(ne.second>=2){ cout<< 0 << endl; return 0;}}
  
  //以後、同じ数字はA,B内に複数回現れない
  
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  
  //でかい方から決めていく
  
  ll ans = 1LL;
  
  
  for(ll i = N*M; i >= 1; i--){
    
    ll res1 = lower_bound(A.begin(),A.end(),i)-A.begin();
    ll res2 = lower_bound(B.begin(),B.end(),i)-B.begin();
    
    
    if( A[res1] == i && B[res2] == i){ //どちらにも含まれている時
      continue;}
    else if(A[res1] == i && B[res2] != i){
      ans *= (M-res2);
      ans %= MOD;
    }
    else if(A[res1] != i && B[res2] == i){
      ans *= (N-res1);
      ans %= MOD;
    }
    else{
      if( (N-res1)*(M-res2) <= (N*M-i)){ ans = 0;}
      ans *= ((N-res1)*(M-res2)-(N*M-i));
      ans = (ans+MOD)%MOD;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}
     
  