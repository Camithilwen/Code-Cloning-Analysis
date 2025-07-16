#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, T;
    cin >> N >> T;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];
    vector<int> ind(N);
    for(int i = 0; i < N; i++) ind[i] = i;
    sort(ind.begin(), ind.end(), [&](int i, int j){
        return A[i] < A[j];
    });
    vector<vector<int>> dp(N + 1, vector<int> (T + 1, 0));
    for(int k = 0; k < N; k++){
        int i = ind[k];
        for(int j = 0; j <= T; j++){
            dp[k + 1][j] = max(dp[k + 1][j], dp[k][j]);
            if(j == T) continue;
            if(j + A[i] > T) dp[k + 1][T] = max(dp[k + 1][T], dp[k][j] + B[i]);
            else dp[k + 1][j + A[i]] = max(dp[k + 1][j + A[i]], dp[k][j] + B[i]);
        }
    }
    cout << dp[N][T] << endl;
}