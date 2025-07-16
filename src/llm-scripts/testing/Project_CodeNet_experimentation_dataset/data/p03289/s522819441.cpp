#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uld = unsigned long long;
using P = pair<int,int>;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
//struct area

//function area

//main area
int main(){
    string s;
    cin >> s;
    int n = s.size();
    bool check = true;
    int C_place;

    //一個目
    if(s[0] != 'A'){
        check = false;
    }

    //二個目
    int cnt = 0;
    for(int i=2; i<n-1; i++){
        if(s[i] == 'C'){
            cnt++;
            C_place = i;
        }
    }
    if(cnt != 1) check = false;

    //三個目
    rep(i, n){
        if(i == C_place || i == 0) continue;
        if(!('a' <= s[i] && s[i] <= 'z')){
            check = false;
        }
    }
    cout << (check ? "AC" : "WA") << endl;
}
/*

一個ずつ判定する
・s[0] == 'A'
・2 <= i <= s.size()-2      cnt = 1
・上二つ以外の座標において'a' <= s[i] <= 'z'を満たす

*/