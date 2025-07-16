#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int N, count = 0;
    cin >> N;
    vector<int> v(N);

    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for(int i=0; i<N; i++) {
        if(v[i] == v[i+1] && i <= N-2) {
            i++;
        }
        else {
            count++;
        }
    }
    cout << count << endl;
}