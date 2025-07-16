#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,M; cin >> N >> M;
    int ans = -1;
    vector<int> s(M);
    vector<char> c(M);
    for (int i=0;i<M;i++) cin >> s[i] >> c[i];
    for (int i = (N==1) ? 0 : pow(10, N-1);i<pow(10,N);i++){
        string x = to_string(i);
        bool can = true;
        for (int j=0;j<M;j++){
            if (x[s[j]-1]!=c[j]) can = false;
        }
        if (can) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}