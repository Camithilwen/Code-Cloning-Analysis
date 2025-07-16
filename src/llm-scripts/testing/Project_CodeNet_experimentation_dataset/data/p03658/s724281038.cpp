#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    int ans = 0;
    for(int i = 0; i < K; i++){
        ans += A.at(N - 1 - i);
    }
    cout << ans << endl;
    return 0;
}