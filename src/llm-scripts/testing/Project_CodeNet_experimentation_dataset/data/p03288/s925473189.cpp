#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
template<typename T> bool chmax(T &a, T b) {if(a <= b){a = b; return true;}return false;}
template<typename T> bool chmin(T &a, T b) {if(a >= b){a = b; return true;}return false;}

#define ABC 001
#define ARC 010
#define AGC 100

int main(void){
    int r;
    cin >> r;
    int frag = AGC;
    if(r < 1200){
        frag |= ABC;
        frag |= ARC;
    }else if( r < 2800){
        frag |= ARC;
    }
    if(frag & ABC)cout << "ABC" << endl;
    else if(frag & ARC)cout << "ARC" << endl;
    else cout << "AGC" << endl;
}