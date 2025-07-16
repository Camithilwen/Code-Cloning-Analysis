#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;

int main(){
 int N, K; cin >> N >> K;
    int ans = 0;
    deque<int> deq;
    vector<int> v(N,0);
    rep(i,N){
        cin >> v[i];
    }
    // 左から取る個数
    for (int l = 0; l <= K; l++){
        // 右から取る個数
        for (int r = 0; r <= K; r++){
            // 取る回数がKを越した場合はNG
            if (l + r > K) continue;
            int d = K - l - r;
            priority_queue<int, vector<int>, greater<int>> tmp;
            // 左から取る
            rep(i,l){
                // dequeの右端に達した場合
                if (i >= N) break;
                tmp.push(v[i]);
            }
            // 右から取る
            rep(i,r){
                int index = N-1-i;
                // dequeの左端もしくはすでに左から取られている場合
                if (index < 0 || index <= l) break;
                tmp.push(v[index]);
            }
            // 手から宝石をつめる
            rep(i,d){
                // 手に持っていない場合
                if (tmp.empty()) break;
                // 価値は正の場合はつめない
                if (tmp.top() >= 0) break;
                tmp.pop();
            }

            int now = 0;
            while (!tmp.empty()){
                now += tmp.top(); tmp.pop();
            }

            ans = max(now, ans);
        }
    }


    cout << ans << endl;
}