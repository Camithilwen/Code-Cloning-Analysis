#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;




int main(){
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    string f="",b="";
    rep(i,ty-sy)f.push_back('U');
    rep(i,tx-sx)f.push_back('R');
    rep(i,ty-sy)b.push_back('D');
    rep(i,tx-sx)b.push_back('L');

    cout << f << b << "LU" << f <<"RDRD" << b << "LU"<<endl;

}
