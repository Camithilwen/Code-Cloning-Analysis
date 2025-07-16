#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
vector<vector<char>> g(100,vector<char>(100));
int main(){
    int a,b; cin >> a >> b;
    rep(i,100){
        rep(j,100){
            if(i < 50) g[i][j] = '#';
            else g[i][j] = '.';
        }
    }

    int p = (a-1)/50;
    for(int i = 0; i < 2*p; i += 2){
        for(int j = 0; j < 100; j += 2){
            g[i][j] = '.';
        }
    }
    int q = (a-1)%50;
    for(int j = 0; j < 2*q; j += 2){
        g[2*p][j] = '.';
    }

    int r = (b-1)/50;
    for(int i = 0; i < 2*r; i += 2){
        for(int j = 0; j < 100; j += 2){
            g[i+51][j] = '#';
        }
    }
    int s = (b-1)%50;
    for(int j = 0; j < 2*s; j += 2){
        g[2*r+51][j] = '#';
    }

    cout << "100 100" << endl;
    rep(i,100){
        rep(j,100){
            cout << g[i][j];
        }
        cout << endl;
    }
}