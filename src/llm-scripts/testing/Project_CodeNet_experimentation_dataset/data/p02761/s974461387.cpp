#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int>c(N, -1);
    int s, t;
    int ans = 0;
    bool b = true;
    for (int i = 0; i < M; i++) {
        cin >> s;
        if (c[s - 1] == -1){
            cin >> c[s - 1];
        }else{
            cin >> t;
            if (c[s - 1] != t) {
                b = false;
                ans = -1;
                break;
            }
        }
    }
    if (c[0] == -1) {
        if (N > 1) {
            c[0] = 1;
        }else {
            c[0] = 0;
        }
        
    }else if (c[0] == 0 && N > 1){
        b = false;
        ans = -1;
    }
    for (int i = 1; i < N; i++) {
        if (c[i] == -1) {
            c[i] = 0;
        }
    }
    if (b) {
        int d = 1;
        for (int i = N - 1; i >= 0; i--) {
            ans += c[i]*d;
            d *= 10;
        }
        
    }
    //cout << c[0] << ',' << c[1] << ',' << c[2] << endl;
    cout << ans << endl;

}
