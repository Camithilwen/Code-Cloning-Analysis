#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e8;


//collision time
int colltime(vector<P> yu){
    int res = iINF;
    sort(yu.begin(),yu.end());
    rep(i,yu.size()-1){
        if( yu[i].second == 0 && yu[i+1].second != 0 ){
            chmin(res, (yu[i+1].first - yu[i].first));
        }
    }
    return res;
}

int min_colltime(map<int,vector<P>>& UD){
    int res = iINF;
    for(auto udi : UD) chmin(res,colltime(udi.second));
    return res;
}


//---main---------------------------------------------
int main(){
    //main
    int N;
    cin >> N;
    vector<int> X(N),Y(N),U(N);
    char c;
    rep(i,N){
        cin >> X[i] >> Y[i] >> c;
        if(c=='U') U[i] = 0;
        if(c=='R') U[i] = 1;
        if(c=='D') U[i] = 2;
        if(c=='L') U[i] = 3;
    }


    int ans = iINF;
    rep(d,4){
        //同じx座標でU,Dのものをまとめる
        map<int,vector<P>> UD;
        rep(i,N) if(U[i]==0 || U[i]==2) UD[X[i]].emplace_back(Y[i],U[i]);
        chmin(ans, min_colltime(UD)*5);

        //同じ直線上でU,Rのものをまとめる
        map<int,vector<P>> UR;
        rep(i,N) if(U[i]==0 || U[i]==1) UR[X[i]+Y[i]].emplace_back(Y[i],U[i]);
        chmin(ans, min_colltime(UR)*10);

        //rotate
        int xi;
        rep(i,N){
            xi = X[i];
            X[i] = Y[i];
            Y[i] = -xi;
            U[i] = (U[i]+1)%4;
        }
    }

    if(ans == iINF) cout << "SAFE" << endl;
    else cout << ans << endl;

    return 0;
}