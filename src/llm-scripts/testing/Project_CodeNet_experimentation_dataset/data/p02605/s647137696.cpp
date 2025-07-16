#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}
 
/*
正面衝突の場合 U-D, L-R
斜め衝突の場合 U-L, L-D, D-R, R-U
 
 
 
 
 
*/
 
 
int x_in[200050], y_in[200050];
char c_in[200050];
vector<pair<int, char>> ur[400020];
vector<pair<int, char>> ud[400020];
 
int n;
 
int solve_UD(){
    rep(i, 400020){
        ud[i].clear();
    }
    rep(i, n){
        if (c_in[i] != 'U' && c_in[i] != 'D') continue;
        ud[x_in[i]].push_back(make_pair(y_in[i], c_in[i]));
    }
    int tmin = 2000001;
    rep(i, 400020){
        sort(ud[i].begin(), ud[i].end());
        rep(j, ud[i].size()-1){
            if (ud[i][j].second == 'U' && ud[i][j+1].second == 'D'){
                tmin = min(tmin, ud[i][j+1].first - ud[i][j].first);
            }
        }
    }
    return tmin * 5;
}
 
int solve_UR(){
    rep(i, 400020){
        ur[i].clear();
    }
    rep(i, n){
        if (c_in[i] != 'U' && c_in[i] != 'R') continue;
        ur[x_in[i]+y_in[i]].push_back(make_pair(x_in[i], c_in[i]));
    }
    int tmin = 2000001;
    rep(i, 400020){
        sort(ur[i].begin(), ur[i].end());
        rep(j, ur[i].size()-1){
            if (ur[i][j+1].second == 'U' && ur[i][j].second == 'R')
            tmin = min(tmin, ur[i][j+1].first - ur[i][j].first);
        }
    }
    return tmin*10;
}
 
void rotate(){
    int tmp;
    rep(i, n){
        tmp = x_in[i];
        x_in[i] = 200000-y_in[i];
        y_in[i] = tmp;
        if (c_in[i] == 'U') c_in[i] = 'L';
        else if (c_in[i] == 'L') c_in[i] = 'D';
        else if (c_in[i] == 'D') c_in[i] = 'R';
        else c_in[i] = 'U';
    }
    
}
 
 
int main()
{
    cin >> n;
    rep(i, n){
        cin >> x_in[i] >> y_in[i] >> c_in[i];
    }
 
    int t_time = 2000001;    
    rep(t, 4){
        t_time = min(t_time, solve_UD());
        t_time = min(t_time, solve_UR());
        rotate();
    }
 
    if (t_time == 2000001) cout << "SAFE" << endl;
    else cout << t_time << endl;
 
}
 