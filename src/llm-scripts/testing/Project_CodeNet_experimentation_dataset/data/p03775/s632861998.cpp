#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

const ll modseed = pow(10,9) + 7;

template <typename T>
vector<T> getValues(int num){
    vector<T> values(num);
    for(int i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

int calcDigit(ll N){
  int digit = 0;
  while(N>0){
    N/= 10;
    digit++;
  }
  return digit;
}

int main(){
  ll N;
  cin >> N;
  int ans = calcDigit(N);
  for(ll A=1;A*A<=N;A++){
    if(N%A!=0){
      continue;
    }
    ll B = N /A;
    int tmp = max(calcDigit(A),calcDigit(B));
    if(ans > tmp){
      ans = tmp;
    }
  }
  printl(ans);
}
