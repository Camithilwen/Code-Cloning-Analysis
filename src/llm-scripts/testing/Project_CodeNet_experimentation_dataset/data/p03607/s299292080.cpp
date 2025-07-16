#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int N;
vector<int> A;


void input() {
    cin >> N;
    A = vector<int>(N);
    rep(i, N) cin >> A[i];
}


int main() {
    input();
    set<int> s;
    for (int a : A) {
        if (s.count(a)) s.erase(a);
        else s.insert(a);
    }
    int ans = s.size();
    cout << ans << endl;
}
