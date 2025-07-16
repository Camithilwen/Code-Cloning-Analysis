#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(long long int i = K; i <= N; i++)
#define ll long long int
#define PP 1000000007
using namespace std;

map<ll, ll> M;

void prime_factor(ll N){

bool C = 1;

while(C){

C = 0;

    rep(i, 2, sqrt(N)){

    if(N%i == 0){M[i]++;N /= i;C = 1;break;}
   
    }

}

M[N]++;

}

int main() {
ll N, Ans = 1;cin >> N;

rep(i, 2, N){

  prime_factor(i);

}

for(auto x : M ){

  Ans *= x.second + 1;Ans %= PP;

}

cout << Ans;

}