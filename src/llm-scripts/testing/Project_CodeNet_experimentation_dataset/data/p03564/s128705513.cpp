#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, n) for(i = 0; i < n; i++)

int main(){
    int N, K;
    int val = 1;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        val = min(val * 2, val + K);
    }

    cout << val << '\n';

    return 0;
}