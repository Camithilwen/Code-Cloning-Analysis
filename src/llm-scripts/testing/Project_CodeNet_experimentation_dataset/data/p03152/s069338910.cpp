#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

ll ca[1111111]={};
ll cb[1111111]={};

int main(){
  ll n,m,p=1e9+7;
  cin>>n>>m;

  ll f=0;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    ca[a]++;
    if(ca[a]==2)f=1;
  }
  for(int i=0;i<m;i++){
    ll b;
    cin>>b;
    cb[b]++;
    if(cb[b]==2)f=1;
  }
  
  ll nm=n*m;
  if(ca[nm]==0||ca[nm]==0||f){
    cout<<0<<endl;
    return 0;
  }

  ll cr=0,cc=0;
  ll ans=1;
  ll c0=0;
  for(int i=nm;i>0;i--){
    //    cout<<ans<<" "<<cr<<" "<<cc<<endl;
    if(ca[i]&&cb[i]){
	 cc++;
	 cr++;
	 c0++;
	 continue;
    }
    if(ca[i]){
	 ans*=cc;
	 ans%=p;
	 cr++;
	 c0++;
	 continue;
    }
    if(cb[i]){
	 ans*=cr;
	 ans%=p;
	 cc++;
	 c0++;
	 continue;
    }
    ans*=(cr*cc-c0);
    ans%=p;
    c0++;
    continue;
  }

  cout<<ans<<endl;
  return 0;
}
