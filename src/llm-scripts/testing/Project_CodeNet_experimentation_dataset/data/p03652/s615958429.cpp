#include<bits/stdc++.h>
using namespace std;
template<class T> void chmax(T& x, T y){if(x < y) x = y;}
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
int N, M;
int A[310][310];
int cnt[310];
bool hold[310];
int idx[310];

int solve(){
    bool flag = false;
    for(int i = 1; i <= M; i++){
        if(hold[i]) flag = true;
    }
    if(!flag) return 1 << 30;

    for(int i = 1; i <= N; i++){
        if(hold[A[i][idx[i]]]) continue;
        for(int& j = idx[i]; j <= M; j++){
            if(hold[A[i][j]]){
                cnt[A[i][j]]++;
                break;
            }
        }
    }

    int mx = 0;
    for(int i = 1; i <= M; i++){
        chmax(mx, cnt[i]);
    }
    set<int> h;
    for(int i = 1; i <= M; i++){
        if(cnt[i] == mx){
            h.insert(i);
            hold[i] = false;
            cnt[i] = 0;
        }
    }
    return min(solve(), mx);
}


int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> A[i][j];
        }
    }
    for(int i = 1; i <= M; i++){
        hold[i] = true;
    }
    cout << solve() << endl;
    return 0;
}