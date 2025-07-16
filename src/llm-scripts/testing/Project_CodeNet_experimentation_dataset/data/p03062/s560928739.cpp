#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);

  int N; cin >> N;
  vector<ll> v(N);
  ll sum = 0;
  int num = 0;

  for(int i = 0; i < N; i++){
    cin >> v[i];

    if(v[i] < 0){
      num++;
      v[i] = abs(v[i]);
    }
  }

  if(num % 2 == 0){
    for(int i = 0; i < N; i++){
      sum += v[i];
    }
  } else { 
    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++){
      if(i==0){
        sum -= v[i];
      } else {
        sum += v[i];
      }
    }
  }

  cout << sum << endl;
}