//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n;
    cin >> n;

    int a, b, c;
    a = 0;
    b = n/2;
    c = n;
    vector<char> st;
    printf("%d\n", 0);
    fflush(stdout);
    string S;
    cin >> S;
    if(S[0] == 'V') return 0;
    st.push_back(S[0]);

    printf("%d\n", b);
    fflush(stdout);
    cin >> S;
    if(S[0] == 'V') return 0;
    st.push_back(S[0]);

    rep(i, 18) {
        if((((b-a)&1) && st[0] != st[1]) || (!((b-a)&1) && st[0] == st[1])) {
            a = b;
            b = (c+b)/2;
            st[0] = st[1];
        } else {
            c = b;
            b = (c+a)/2;
        }
        printf("%d\n", b);
        fflush(stdout);
        cin >> S;
        if(S[0] == 'V') return 0;
        st[1] = S[0];
    }

}