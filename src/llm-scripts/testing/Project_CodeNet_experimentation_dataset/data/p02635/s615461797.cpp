#include "bits/stdc++.h"
using namespace std;
#define REP(i, n) for(ll i = 0;i < n;i++)
#define ll long long
#define MOD 998244353LL
#define llMAX 9223372036854775807LL
#define llMIN -9223372036854775808LL
using vi = vector<ll>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける

ll n,x,y,K_;

int main(){
  ll ans=0;
  string s;cin>>s;
  cin >> K_;
  n=s.length();
  ll zn=0;
  for(ll i=0;i<n;i++){
    if (s[i]=='0')zn++;
  }
  ll nn=n-zn;//1の数
  K_=min(K_,nn);

  if ((n==zn)|(zn==0)|(K_==0)){
    cout<<1<<endl;
    return 0;
  }

  zn++;
  vvi zrange(zn, vi(2));//0からみて左に1が今何個減らせるか、最大何個まで増やせるか
  ll znw=zn-1;
  ll totalone=0;
  s+="0";
  for(ll i=n;i>=0;i--){
    if (s[i]=='0')
    {
      zrange[znw][1]=totalone;
      for(;;)
      {
        i--;
        if (i==-1)break;
        if (s[i]=='1'){
          zrange[znw][0]++;
          totalone++;
        }else{i++;break;}
      }
      znw--;
    }else{
      totalone++;
    }
  }

  /*
  for(ll i=0;i<zn;i++){
    cout<<zrange[i][0]<<" "<<zrange[i][1]<<endl;
  }
  */
  

/*
  for(ll i=0;i<zn;i++){
    zrange[i][1]+=zrange[i][0];
  }
*/


  vi dp(nn+1,0);
  vi dp_n(nn+1,0);
  vvi score(nn+1, vi(K_*2+1,0));
  vvi score_n(nn+1, vi(K_*2+1,0));

  dp[0]=1;
  score[0][0]=1;
  for(ll i=0;i<zn;i++){//さいがいループ、0の左に何個つけられるか

    for(ll j=0;j<nn+1;j++){
      dp_n[j]=0;
      for(ll k=max(j-zrange[i][1],0LL);k<=min(j+zrange[i][0],nn);k++){
        dp_n[j]+=dp[k];
        for(ll l=0;l+abs(j-k)<K_*2+1;l++){
          score_n[j][l+abs(j-k)]+=score[k][l];
          score_n[j][l+abs(j-k)]%=MOD;
        }
      }
      dp_n[j]%=MOD;
    }

    /*
    for(ll j=0;j<nn+1;j++){
      dp[j]=dp_n[j];
      dp_n[j]=0;
    }
    */
    dp.swap(dp_n);
    for(ll j=0;j<nn+1;j++){
      for(ll k=0;k<K_*2+1;k++){
        score[j][k]=score_n[j][k];
        score_n[j][k]=0;
      }
    }
    //score.swap(score_n);
  }


  //cout<<dp[0]<<endl;

  for(ll i=0;i<K_*2+1;i++){
    //cout<<score[0][i]<<endl;
    ans+=score[0][i];
    ans%=MOD;
  }






  cout<<ans<<endl;
  return 0;
}