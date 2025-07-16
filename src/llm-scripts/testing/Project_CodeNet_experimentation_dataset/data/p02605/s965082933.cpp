#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N; cin >> N;
    vector<int> X(N);
    vector<int> Y(N);
    vector<char> U(N);
    REP(i,N) cin >> X[i] >> Y[i] >> U[i];

    int ans = INF;

    vector<vector<pair<int,char>>> H(1e6);//縦方向

    REP(i,N){
        if(U[i]=='U' || U[i]=='D'){
            H[X[i]].push_back({Y[i],U[i]});
        }
    }
    REP(i,H.size()){
        if(H[i].size()==0) continue;
        sort(ALL(H[i]));
        REP(j,H[i].size()-1){
            if(H[i][j].second=='U' && H[i][j+1].second=='D'){
                ans = min(ans, 5*(H[i][j+1].first - H[i][j].first));
            }
        }
    }

    vector<vector<pair<int,char>>> V(1e6);//横方向
    REP(i,N){
        if(U[i]=='R' || U[i]=='L'){
            V[Y[i]].push_back({X[i],U[i]});
        }
    }
    REP(i,V.size()){
        if(V[i].size()==0) continue;
        sort(ALL(V[i]));
        REP(j,V[i].size()-1){
            if(V[i][j].second=='R' && V[i][j+1].second=='L'){
                ans = min(ans, 5*(V[i][j+1].first - V[i][j].first));
            }
        }
    }

    vector<int> XX(N);
    vector<int> YY(N);

    REP(i,N){//45度回転
        XX[i] = X[i]-Y[i]+200000;
        YY[i] = X[i]+Y[i]+200000;
    }

    vector<vector<pair<int,char>>> V1(1e6);//横方向
    REP(i,N){
        if(U[i]=='R' || U[i]=='U'){
            V1[YY[i]].push_back({XX[i],U[i]});
        }
    }
    REP(i,V1.size()){
        if(V1[i].size()==0) continue;
        sort(ALL(V1[i]));
        REP(j,V1[i].size()-1){
            if(V1[i][j].second=='R' && V1[i][j+1].second=='U'){
                ans = min(ans, 5*(V1[i][j+1].first - V1[i][j].first));
            }
        }
    }

    vector<vector<pair<int,char>>> V2(1e6);//横方向
    REP(i,N){
        if(U[i]=='D' || U[i]=='L'){
            V2[YY[i]].push_back({XX[i],U[i]});
        }
    }
    REP(i,V2.size()){
        if(V2[i].size()==0) continue;
        sort(ALL(V2[i]));
        REP(j,V2[i].size()-1){
            if(V2[i][j].second=='D' && V2[i][j+1].second=='L'){
                ans = min(ans, 5*(V2[i][j+1].first - V2[i][j].first));
            }
        }
    }

    vector<vector<pair<int,char>>> H1(1e6);//横方向
    REP(i,N){
        if(U[i]=='R' || U[i]=='D'){
            H1[XX[i]].push_back({YY[i],U[i]});
        }
    }
    REP(i,H1.size()){
        if(H1[i].size()==0) continue;
        sort(ALL(H1[i]));
        REP(j,H1[i].size()-1){
            if(H1[i][j].second=='R' && H1[i][j+1].second=='D'){
                ans = min(ans, 5*(H1[i][j+1].first - H1[i][j].first));
            }
        }
    }

    vector<vector<pair<int,char>>> H2(1e6);//横方向
    REP(i,N){
        if(U[i]=='U' || U[i]=='L'){
            H2[XX[i]].push_back({YY[i],U[i]});
        }
    }
    REP(i,H2.size()){
        if(H2[i].size()==0) continue;
        sort(ALL(H2[i]));
        REP(j,H2[i].size()-1){
            if(H2[i][j].second=='U' && H2[i][j+1].second=='L'){
                ans = min(ans, 5*(H2[i][j+1].first - H2[i][j].first));
            }
        }
    }

    if(ans == INF) cout << "SAFE" << endl;
    else cout << ans << endl;
    return 0;
}