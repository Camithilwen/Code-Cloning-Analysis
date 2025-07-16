#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int MAX = 55555;

int main(){
    int n;
    cin >> n;

    VI d(MAX + 1);
    for(int i = 1; i <= MAX; i++){
        for(int j = i; j <= MAX; j += i){
            d[j]++;
        }
    }
    

    int cnt = 0, i = 3;
    VI ans;
    while(cnt < n){
        if(d[i] == 2 && i % 5 == 3){
            ans.push_back(i);
            cnt++;
        }
        i++;
    }

    rep(i,n) printf("%d%c", ans[i], i == n-1? '\n' : ' ');
    return 0;
}
