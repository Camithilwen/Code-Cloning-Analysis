#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { //最大公約数
  if (b==0) return a;
  else return gcd(b, a%b);
}

ll lcm(ll a, ll b) { //最小公倍数
  return a * b / gcd(a, b);
}

ll digit_sum(ll a){ //10進桁和
  ll ans=0;
  while(a>0){
    ans+=a%10;
    a/=10;
  }
  return ans;
}



int main()
{
  ll n,m,X,Y,x[110],y[110];
  cin>>n>>m>>X>>Y;
  rep(i,n)cin>>x[i];
  rep(i,m)cin>>y[i];

  for(ll i=X+1;i<=Y;i++){
    ll tmp1=0,tmp2=0;
    rep(j,n){
      if(x[j]>=i){
        tmp1++;
      }
    }
    rep(k,m){
      if(y[k]<i){
        tmp2++;
      }
    }
    if(tmp1==0&&tmp2==0){
      cout<<"No War"<<endl;
      return 0;
    }
  }

  cout<<"War"<<endl;
  return 0;
}
