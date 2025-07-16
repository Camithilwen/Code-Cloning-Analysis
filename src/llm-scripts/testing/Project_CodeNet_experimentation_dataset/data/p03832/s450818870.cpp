#include <bits/stdc++.h>
 
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
const double pi = acos(-1.);
//printf(%.12lf\n,mid);
// __builtin_popcount(int) count 1's in binary
// get decimal part of number
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
// round = (int)(num+.5)
long long mod = 1000000007;

// 32 mil = ~1 sec 
long long mymod(long long num){
  if (num< 0 && !(num%mod == 0)){
    if (mod == 1){
      return 0;
    }
    return mod-abs(num)%mod;
  }else{
    return num%mod;
  }
}
 
/*string sentence = And I feel fine...;
    istringstream iss(sentence);
*/  
 
double eps = .000000001;


long long modpow(long long x, long long n) { 
  if (n == 0) return 1%mod; 
  long long u = modpow(x,n/2); 
  u = (u*u)%mod; 
  if (n%2 == 1) u = (u*x)%mod; 
  return u;
}
long long n, a, b, c, d;
bool memoo[1001][1001];
long long memo[1001][1001];
long long shortmod(long long num){
    if (num >= mod){
        num -= mod;
    }
    return num;
}
void EE(int a, int b, int& x, int& y)
{
    if(a%b == 0)
    {
        x=0;
        y=1;
        return;
    }
    EE(b,a%b,x,y);
    int temp = x;
    x = y;
    y = temp - y*(a/b);
}
int inverse(int a)
{
    int x,y;
    EE(a,mod,x,y);
    if(x<0) x += mod;
    return x;

}
long long facts[1001];
long long invfacts[1001];
long long inverses[1001];
long long func(int left, int grpsze){
  
    if (left == 0 && grpsze > b){
        return 1;
    }
    if (left < 0 || grpsze > b){
        return 0;
    }
    
    if (memoo[left][grpsze]){
        return memo[left][grpsze];
    }
    long long res = 0;
    
    long long choose = 1;
    int templeft = left;
 
    templeft -= grpsze*(c-1);
    choose *= modpow(invfacts[grpsze], c-1);
    choose %= mod;
    choose *= invfacts[c-1];
    choose %= mod;
    for (int i=c; i <= d; i++){
        if (templeft <= 0){
            break;
        }
        choose *= invfacts[grpsze];
        choose %= mod;
        choose *= inverses[i];
        choose %= mod;
        templeft -= grpsze;
        res += (choose*func(templeft, grpsze+1))%mod;
        res = shortmod(res);
        
    }
    res += func(left, grpsze+1);
    res = shortmod(res);
    memoo[left][grpsze] = true;
    memo[left][grpsze] = res;
    return res;
}
int main ()
{
  prep();
  
  cin >> n >> a >> b >> c >> d;
 
  long long cur = 1;
  for (int i=1; i<=1000; i++){
      cur *= i;
      cur %= mod;
      facts[i] = cur;
  }
  facts[0] = 1;
  invfacts[0] = 1;
  inverses[0] = 1;
  cur = 1;
  for (int i=1; i<=1000; i++){
      cur *= inverse(i);
      cur %= mod;
      invfacts[i] = cur;
  }
  for (int i=1; i<=1000; i++){
      inverses[i] = inverse(i);
  }
  cout << (facts[n]*func(n, a))%mod;
  
  return 0; 
}
