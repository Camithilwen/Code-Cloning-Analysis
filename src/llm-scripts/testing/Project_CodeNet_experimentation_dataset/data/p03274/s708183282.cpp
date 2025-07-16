#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,K,cnt,sum,minsum,minsumtemp;
    cin >> N >> K;

    vector<int> x(N);
    vector<int> diff(N-1);
    for(int i=0;i<N;i++) {
        cin >> x[i];
        if(i) diff[i-1] = x[i]-x[i-1];
    }

    cnt = 0;
    sum = 0;
    minsum = INT_MAX;
    for(int i=0;i<(K-1);i++) {
        sum += diff[i];
    }
    if(abs(x[K-1]) < abs(x[0])) {
        minsum = sum + abs(x[K-1]);
    } else {
        minsum = sum + abs(x[0]);
    }

    for(int i=(K-1);i<(N-1);i++) {
        sum += diff[i];
        sum -= diff[i-K+1];
        if(abs(x[i+1]) < abs(x[i-K+2])) {
            minsumtemp = sum + abs(x[i+1]);
        } else {
            minsumtemp = sum + abs(x[i-K+2]);
        }
        if(minsumtemp < minsum) {
            minsum = minsumtemp;
        }
    }

    cout << minsum << endl;

    return 0;
}
