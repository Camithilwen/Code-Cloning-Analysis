#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <math.h>
#include <map>
#include <stack>
using namespace std;
static const int INF = 1e9+7;
// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, a, b) for (int i =a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define PI 3.14159265359

int main(){
    string S; cin >> S;
    ll res = 1000000000;

    rep(i, S.size()-2){
        int tmp = (S[i] - '0')*100 + (S[i+1] - '0')*10 + (S[i+2]-'0');
        int tmp2 = abs(tmp - 753);
        if(tmp2 < res){
            res = tmp2;
        }
    }
        cout << res << endl;
    return 0;
}
