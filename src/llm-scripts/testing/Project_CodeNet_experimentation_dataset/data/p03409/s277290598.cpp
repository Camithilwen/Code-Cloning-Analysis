//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

int main(){
    ll N;
    cin>>N;
    vector<ll> a(N),b(N),c(N),d(N);
    REP(i,N){
        cin>>a[i]>>b[i];
    }

    REP(i,N){
        cin>>c[i]>>d[i];
    }
    vector<vector<bool>> p(110,vector<bool>(110,false));
    ll cnt=0;
    REP(i,N){
        REP(j,N){
            if(a[i]<c[j]&&b[i]<d[j]){
                p[i][j]=true;
                cnt++;
            }
        }
    }
    ll lose=INF;
    ll ans=0;
    while(lose>0){
        ll lose_m=INF;
        ll idx=-1,jdx=-1;
        REP(i,N){
            REP(j,N){
                if(p[i][j]==false) continue;
                lose=0;
                REP(k,N){
                    if(p[i][k]==true) lose++;
                    if(p[k][j]==true) lose++;
                }
                lose--;
                if(lose<lose_m){
                    lose_m=lose;
                    idx=i;
                    jdx=j;
                }
            }
        }
        if(idx==-1||jdx==-1) break;
        REP(k,N){
            p[idx][k]=false;
            p[k][jdx]=false;
        }

        cnt-=lose_m;
        ans++;

    }
    cout<<ans<<endl;
    


}