#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int K, T;
    cin >> K >> T;
    vector<int> A(T+1);
    rep(i, T) cin >> A[i];
    vector<int> ans;
    int cnt = 0;
    int pre_idx = -1;
    int now_idx = T;
    rep(i, K){
        rep(j, T){
            if(pre_idx == j) continue;
            if(A[now_idx] < A[j]) now_idx = j;
        }
        if(now_idx == T){
            now_idx = pre_idx;
            cnt += 1;
        }
        A[now_idx] -= 1;
        ans.push_back(now_idx);
        pre_idx = now_idx;
        now_idx = T;
        
    }
    cout << cnt << endl;
    return 0;
}
