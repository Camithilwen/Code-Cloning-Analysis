#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i < N; i++)
#define ll long long int
using namespace std;

int main(){
ll N, Ans = 1000000000, K;cin >> N >> K;
bool C = 0;
vector<ll> n;
vector<ll> p{0};

rep(i, 0, N){

    ll a;cin >> a;

    if(a == 0)continue;

    if(a > 0)C = 1;

    if(C)p.push_back(a);

    else n.push_back(a);

}

n.push_back(0);
reverse(ALL(n));
  
if(p == n && p.size() == 1){cout << 0;exit(0);}
  
//for(auto q : n)cout << q << endl;
  
int A = K - n.size() + 1, B = K, D = p.size() - 1;
  

for(ll i = max(A, 0); i <= min(B, D); i++){

    Ans = min(Ans, min(2*p[i] + abs(n[K - i]), 2*abs(n[K - i]) + p[i]));


}

cout << Ans;

}