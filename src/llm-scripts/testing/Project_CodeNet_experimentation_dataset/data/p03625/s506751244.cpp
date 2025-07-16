#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;

int gcd(int a, int b) { //最大公約数
  if (b==0) return a;
  else return gcd(b, a%b);
}

int lcm(int a, int b) { //最小公倍数
  return a * b / gcd(a, b);
}


int main()
{
  ll n,a[100010];
  cin>>n;
  rep(i,n)cin>>a[i];
  sort(a,a+n,greater<ll>());

  ll tate=0,yoko=0,cnt=0;

  rep(i,n-1){
    if(cnt==0&&a[i]==a[i+1]){
      tate=a[i];
      cnt=1;
      i++;
    }else if(cnt==1&&a[i]==a[i+1]){
      yoko=a[i];
      cnt=2;
    }
  }

  if(tate==0||yoko==0){
    cout<<0<<endl;
  }else{
    cout<<tate*yoko<<endl;
  }

  return 0;
}
