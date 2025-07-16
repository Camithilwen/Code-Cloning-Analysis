#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ll long long
long long min(long long x,long long y){return (x<y ? x:y);}
long long max(long long x,long long y){return (x>y ? x:y);}
#define ld long double
int stoi(string s) {return atoi(s.c_str());}
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
#define LINEY "YES\n"
#define Liney "Yes\n"
#define LINEN "NO\n"
#define Linen "No\n"

void func(ll* x,ll* y){
  *x -= (*x%2);
  *x /= 2;
  *y += *x;
}

int main(){
  ll A,B;
  int K;
  cin >> A>>B>>K;
  bool turn_A = true;
  REP(i,K){
    if(turn_A){func(&A,&B);}
    else{func(&B,&A);}
    turn_A = !turn_A;
  }
  printf("%d %d\n",A,B);
}