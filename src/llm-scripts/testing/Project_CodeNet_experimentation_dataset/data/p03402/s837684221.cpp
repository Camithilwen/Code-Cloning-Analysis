#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;


int main(){
    int a,b; cin >> a >> b;
    int h = 100, w = 100;
    // int h = 10, w = 10;
    // vector<string> s(h);
    string s[h];
    rep(i,h)rep(j,w){
        if(i*2 < h)s[i] += '#';
        else s[i] += '.';
    }
    int cnt = 0;
    int x = 0, y = 0;
    int dx[8] = {0,0,1,-1,1,-1,1,-1};
    int dy[8] = {-1,1,0,0,1,-1,-1,1};
    while(cnt < a-1){
        bool ok = true;
        rep(i,8){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && h > nx && ny >= 0 && w > ny){
                if(s[nx][ny] == '.')ok = false;
            }
        }
        if(ok){
            s[x][y] = '.';
            ++cnt;
        }
        if(y < w-1)++y;
        else{y = 0;++x;}
    }

    x = h-1;
    y = w-1;
    cnt = 0;
    while(cnt < b-1){
        bool ok = true;
        rep(i,8){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && h > nx && ny >= 0 && w > ny){
                if(s[nx][ny] == '#')ok = false;
            }
        }
        if(ok){
            s[x][y] = '#';
            ++cnt;
        }
        if(0 < y)--y;
        else{y = w-1;--x;}
    }
    cout << h << " " << w << endl;
    rep(i,h){
        rep(j,w)cout << s[i][j];
        cout << "\n";
    }
    return 0;
}