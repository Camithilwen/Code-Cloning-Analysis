#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,n) for(int i=1; i<=(n); ++i)
#define all(x) (x).begin(),(x).end()
#define sort_u(x) sort((x).begin(),(x).end())
#define sort_d(x) sort((x).begin(),(x).end(), greater<int>())
#define pb push_back
#define INF ((1LL<<62)-(1LL<<31))  // 浮動小数点型
#define bit(n,m)(((n)>>(m))&1)  // nのmビット目が1
#define MOD 1000000007
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<P>>;

int main() {
    int n; cin >> n;
    Graph p(n);
    rep(i,n){
        int a; cin >> a;
        rep(j, a){
            int x, y; cin >> x >> y;
            x--;
            p[i].pb(P(x,y));
        }
    }
    int ans = 0;
    rep(s, 1<<n){
        vector<int> flg(n, -1);
        bool flg2 = false;
        int a = 0;
        rep(i,n){
            if(bit(s,i)){
                if(flg[i] == -1) flg[i] = 1;
                if(flg[i] != 1) {
                    flg2 = true;
                    break;
                }
                a++;
                for(auto q : p[i]){
                    if(flg[q.first] == -1) flg[q.first] = q.second;
                    if(flg[q.first] != q.second){
                        flg2 = true;
                        break;
                    }
                }
            }else{
                if(flg[i] == -1) flg[i] = 0;
                if(flg[i] != 0) {
                    flg2 = true;
                    break;
                }
                // for(auto q : p[i]){
                //     int q2 = 1;
                //     if(q.second == 1) q2 = 0;
                //     if(flg[q.first] == -1) flg[q.first] = q2;
                //     if(flg[q.first] == q.second){
                //         flg2 = true;
                //         break;
                //     }
                // }
            }
            if(flg2) break;
        }
        if(!flg2) ans = max(a,ans);
    }
    cout << ans << endl;
    
}

/*
g++ c.cpp
./a.out


oj d
g++ c.cpp
oj t
*/
