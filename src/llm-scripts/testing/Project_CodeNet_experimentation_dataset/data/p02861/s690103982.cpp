#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;
typedef long double ld;
/*
void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}
*/
int main() {
    int N;
    cin >> N;
    vector<ld> x(N), y(N);
    for (int i=0; i<N; i++) cin >> x[i] >> y[i];
    vector<ld> base(N), L(N-1);
    for (int i=0; i<N; i++) base[i] = i;
    int p=1;
    for (int i=1; i<=N; i++) p*=i;
    ld cnt = 0;
    for (int i=0; i<p; i++) {
        for (int j=0; j<N-1; j++) {
            cnt += sqrt(pow(x[base[j+1]]-x[base[j]],2)+pow(y[base[j+1]]-y[base[j]],2));
        }
        next_permutation(base.begin(),base.end());
    }
    ld ans = cnt/p;
    cout << fixed << setprecision(8);
    cout << ans << endl;
}