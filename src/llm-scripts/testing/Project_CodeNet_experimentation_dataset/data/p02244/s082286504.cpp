#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define all(x) x.begin(),x.end()
#define br cout << "\n";
using namespace std;
const long long INF = 1e10;
const long long MOD = 1e9+7;
using Graph = vector<vector<ll>>;
using pll = pair<ll, ll>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// a to A : -32
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

vector<ll> tate; vector<ll> yoko;

void f(vector<vector<string>> chess, ll count){
    
    if(count == 8){
        bool flag = true;
        rep(i, tate.size()){
            if(chess[tate[i]][yoko[i]] != "Q") flag = false;
        }

        if(flag){
            rep(i, 8){
                rep(j, 8){
                    cout << chess[i][j];
                }
                br;
            }
        }
    }else{
        rep(j, 8){
            //縦
            bool tate_flag = true;
            for(ll k = count-1; k >= 0; k--){
                if(chess[k][j] == "Q") tate_flag = false;
            }  

            bool naname_flag = true;
            for(ll k = count, l = j; k >= 0 && l >= 0; k--, l--){
                if(chess[k][l] == "Q") naname_flag = false;
            }
            for(ll k = count, l = j; k >= 0 && l < 8; k--, l++){
                if(chess[k][l] == "Q") naname_flag = false;
            }
            for(ll k = count, l = j; k < 8 && l >= 0; k++, l--){
                if(chess[k][l] == "Q") naname_flag = false;
            }
            for(ll k = count, l = j; k < 0 && l < 0; k++, l++){
                if(chess[k][l] == "Q") naname_flag = false;
            }

            if(tate_flag && naname_flag){
                chess[count][j] = "Q";
                f(chess, count+1);
                chess[count][j] = ".";
            }
        }
    }
    
}


int main() {
    std::cout << std::fixed << std::setprecision(15);
    ll k; cin >> k;
    
    rep(i, k){
        ll a, b;
        cin >> a >> b;
        tate.push_back(a); yoko.push_back(b);
    }

    vector<vector<string>> chess(8, vector<string>(8));
    rep(i, 8)rep(j, 8){
        chess[i][j] = ".";
    }

    rep(i, 8){
        chess[0][i] = "Q";
        f(chess, 1);
        chess[0][i] = ".";
    }

}
