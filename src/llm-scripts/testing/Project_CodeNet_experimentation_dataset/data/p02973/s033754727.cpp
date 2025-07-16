#include <bits/stdc++.h>
#define INF 2e9
using namespace std;
using ll = long long;

int main(void) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    deque<int> d;

    for (int i = 0; i < N; i++)
    {
        int pos = lower_bound(d.begin(), d.end(), A[i]) - d.begin();
        if(pos == 0){
            d.push_front(A[i]);
        } else {
            d[pos-1] = A[i];
        }
    }

    int ans = d.size();

    cout << ans << endl;
    
    return 0;
}
