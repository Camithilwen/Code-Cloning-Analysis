#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    partial_sum(A.begin(), A.end(), A.begin());

    int64_t ans = numeric_limits<int64_t>::max();
    int64_t P, Q, R, S;
    int low, mid, high;
    for(int r=1; r<N-2; r++) {
        low = 0;
        high = r;
        while(low + 1 < high) {
            mid =(low + high) / 2;
            if(2*A[mid] <= A[r]) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if(max(A[low], A[r] - A[low]) - min(A[low], A[r] - A[low]) < max(A[high], A[r] - A[high]) - min(A[high], A[r] - A[high])) {
            P = A[low];
            Q = A[r] - A[low];
        } else {
            P = A[high];
            Q = A[r] - A[high];
        }

        low = r+1;
        high = N-1;
        while(low + 1 < high) {
            mid =(low + high) / 2;
            if(2*(A[mid] - A[r]) <= A[N-1] - A[r]) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if(max(A[low] - A[r], A[N-1] - A[low]) - min(A[low] - A[r], A[N-1] - A[low]) < max(A[high] - A[r], A[N-1] - A[high]) - min(A[high] - A[r], A[N-1] - A[high])) {
            R = A[low] - A[r];
            S = A[N-1] - A[low];
        } else {
            R = A[high] - A[r];
            S = A[N-1] - A[high];
        }

        ans = min(ans, max({P, Q, R, S}) - min({P, Q, R, S}));
    }

    cout << ans << endl;
    return 0;
}
