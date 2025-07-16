#include<bits/stdc++.h>

using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    int count = 0;
    const int INF = 2000000000;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 最長減少(等しい場合も含む)部分列の数列の長さがi+1のときの最終要素の最大値dp[i]?
    vector<int> dp;

    // 初期条件
    dp.push_back(A[0]);

    // dp開始
    for(int i = 1; i < N; i++) {
        // dp[i]の右から走査
        auto iter = lower_bound(dp.rbegin(), dp.rend(), A[i]);

        // A[i]が右端の値以下の場合
        if(iter == dp.rbegin()) {
            dp.push_back(A[i]);

        // A[i]より小さい値がdp[i]に存在する場合
        } else {
            *(iter-1) = A[i];            
        }
    }

    // dp[i]の大きさが答え    
    cout << dp.size() << endl;
	return 0;
}
