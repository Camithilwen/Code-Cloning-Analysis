#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素


int main(){
    int N;
    string S;
    cin>>N>>S;
    vector<int> v(3);
    rep(i,N) v[S[i]%3]++;
    ll ans=(ll)v[0]*v[1]*v[2];
    ll sub=0;
    rep(i,N){
        for(int j=i+1;j<N;j++){
            if(S[i]==S[j]) continue;
            int k=2*j-i;
            if(k>=N) continue;
            if(S[i]==S[k] || S[j]==S[k]) continue;
            sub++;
        }
    }
    ans-=sub;
    cout<<ans<<endl;
    return 0;
}
