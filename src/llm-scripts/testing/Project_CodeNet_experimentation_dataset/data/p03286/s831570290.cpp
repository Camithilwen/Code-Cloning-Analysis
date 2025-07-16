#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
static const double pi = 3.141592653589793;




int main(){
    ll N;
    cin>>N;
    if(N==0){
        cout<<0<<endl;
        return 0;
    }
    if(N==1){
        cout<<1<<endl;
        return 0;
    }
    if(N>0){
        ll Num=0;
        ll Key=1;
      	ll Keta=-2;
        while(Num<N){
            Num+=Key;
            Key*=4;
          	Keta+=2;
        }
        ll Dif=Num-N;
        ll J=1;
        cout<<1;
        vector<ll> W(Keta, 0);
      	ll i=0;
        while(Dif>0){
            W[i]=Dif%2;
          	i++;
            Dif/=2;
        }
        
        rep(i, Keta){
            if(J+1){
				cout<<W[Keta-1-i];
            }else{
              	cout<<(1-W[Keta-1-i]);
            }
          
          	J*=-1;
        }
    }
  	if(N==-1){
      	cout<<11<<endl;
      return 0;
    }
  	if(N<0){
      	ll Num=0;
        ll Key=2;
      	ll Keta=-1;
        while(Num<N*-1){
            Num+=Key;
          	Keta+=2;
            Key*=4;
        }
        ll Dif=Num-N*-1;
      	cout<<1;
        vector<ll> W(Keta, 0);
      	ll i=0;
        while(Dif>0){
            W[i]=Dif%2;
          	i++;
            Dif/=2;
        }
      	ll J=1;
        rep(i, Keta){
            if(J+1){
				cout<<W[Keta-1-i];
            }else{
              	cout<<(1-W[Keta-1-i]);
            }
          
          	J*=-1;
        }
    }
}
    