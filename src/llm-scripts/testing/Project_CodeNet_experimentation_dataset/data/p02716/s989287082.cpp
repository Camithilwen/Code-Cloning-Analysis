#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>

using ll = long long int;
using namespace std;

int main(){

  ll N, tmp;
  vector<ll> A;
  cin >> N;
  for(ll i = 0; i < N; i++){
    cin >> tmp;
    A.push_back(tmp);
  }

  // if N is even
  if(N%2 == 0){
    cerr << "N is even." << endl;
    vector<ll> accum(N);
    accum[0] = A[0];
    for(ll i = 2; i < N; i+=2){
      accum[i] = accum[i-2] + A[i];
    }
    accum[N-1] = A[N-1];
    for(ll i = N-3; i >= 1; i-=2){
      accum[i] = accum[i+2] + A[i];
    }
    ll ans = max(accum[N-2], accum[1]);
    for(ll i = 0; i<=N-4; i+=2){
      ans = max(ans, accum[i]+accum[i+3]);
    }

    cerr << "Answer:" << endl;
    cout << ans << endl;

    return 0;
  }
  // N is odd
  else{
    cerr << "N is odd." << endl;
    vector<ll> accum(N);
    accum[0] = A[0];
    for(ll i = 2; i < N; i++){
      accum[i] = accum[i-2] + A[i];
    }
    accum[N-2] = A[N-2];
    for(ll i = N-4; i >= 1; i-=2){
      accum[i] = accum[i+2] + A[i];
    }
    vector<ll> diff(N);
    for(ll i = 1; i <= N-4; i+=2){
      diff[i] = accum[i-1] + accum[i+2] - accum[1];
    }
    for(ll i = 2; i <= N-3; i+=2){
      diff[i] = accum[N-1]-accum[i] + accum[1] - accum[i+1] - accum[1];
    }
    diff[N-2] = accum[N-3] - accum[1];
    diff[0] = accum[2] - accum[1];

    vector<ll> eomax(N);
    eomax[N-3] = diff[N-3];
    for(ll i = N-5; i >= 0; i-=2){
      eomax[i] = max(eomax[i+2], diff[i]);
    }

    ll ans = max(max(accum[N-1]-accum[0], accum[N-3]), accum[1]);
    for(ll oe = 1; oe < N-2; oe+=2){
        ans = max(ans, accum[1]+diff[oe]+eomax[oe+1]);
    }

    cerr << "Answer:" << endl;
    cout << ans << endl;

    return 0;
  }


  
}
