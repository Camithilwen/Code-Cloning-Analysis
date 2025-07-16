#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<62;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;


int main(){
    int N; cin >> N;
    vector<vector<int>> A(N,vector<int>(N-1));
    rep(i,N){
        rep(j,N-1){
            cin >> A[i][j];
            A[i][j]--;
        }

        // vectorは末尾の削除は早いが、先頭は遅いのでreverse
        reverse(A[i].begin(), A[i].end());
    }

    vector<pair<int,int>> q;
    // 試合を登録
    auto check = [&](int i){
        if (A[i].size() == 0) return;
        int j = A[i].back();
        if (A[j].size() == 0) return;
        if (A[j].back() == i){
            P p(i,j);
            if (p.second < p.first) swap(p.first, p.second);
            q.push_back(p);
        }
    };
    rep(i,N){
        check(i);
    }
    int day = 0;
    while (q.size() > 0){
        day++;
        // 重複を削除する前準備としてソートしておく。
        sort(q.begin(), q.end());
        // 重複を削除
        q.erase(unique(q.begin(),q.end()), q.end());
        vector<pair<int,int>> prevQ;
        
        // prevQにqを入れて, qを空にする。
        // vectorのswapは早い
        swap(prevQ, q);
        
        for (auto p : prevQ){
            int i = p.first, j = p.second;
            // 試合を行う。
            // pop_back()は末尾の要素の削除
            A[i].pop_back();
            A[j].pop_back();
        }
        // 翌日の試合を登録
        for (auto p : prevQ){
            int i = p.first, j = p.second;
            check(i);
            check(j);
        }
    }

    rep(i,N){
        // 試合が残ってしまったら-1
        if (A[i].size() != 0){
            puts("-1");
            return 0;
        }
    }

    cout << day << endl;

} 