#include <bits/stdc++.h>
 
using namespace std;

#define INF (1<<29)

set<string> st;

void solve(int K, int S, vector<string> &s, string str)
{
    if (K == 0) {
        st.insert(str);
        return;
    }
    
    int N = s.size();
    for (int i = 0; i < N; i++) {
        if (S >> i & 1) continue;
        solve(K-1, S|(1<<i), s, str + s[i]);
    }
}

int main()
{
    int N, K;
    while (cin >> N, N) {
        vector<string> s(N);
        cin >> K;
        for (int i = 0; i < N; i++) {
            cin >> s[i];
        }
        st.clear();
        solve(K, 0, s, "");
        cout << st.size() << endl;
    }
    return 0;
}