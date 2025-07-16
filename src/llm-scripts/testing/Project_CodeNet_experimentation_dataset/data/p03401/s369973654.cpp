#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,sum;
    cin >> N;
    vector<int> A(N+2,0);
    vector<bool> bs(N+1,false);

    // 経由地点が間にあるかどうかを判定する
    sum = 0;
    for(int i=0;i<N;i++) {
        cin >> A[i+1];
        if(i) {
            // 2個前と1個前と現在を見て1個前を確定
            if(((A[i+1] >= A[i]) && (A[i] >= A[i-1]))
                || ((A[i+1] <= A[i]) && (A[i] <= A[i-1]))) {
                bs[i] = true;
            }
        }
        sum += abs(A[i+1] - A[i]);
    }

    // 最後を確定
    if(((A[N+1] >= A[N]) && (A[N] >= A[N-1]))
                || ((A[N+1] <= A[N]) && (A[N] <= A[N-1]))) {
        bs[N] = true;
    }
    sum += abs(A[N+1] - A[N]);


    for(int i=1;i<=N;i++){ 
        if(bs[i]) {
            cout << sum << endl;   
        } else {
            cout << sum - abs(A[i]-A[i-1]) - abs(A[i+1]-A[i]) + abs(A[i+1]-A[i-1]) << endl;
        }
    }
    return 0;
}
