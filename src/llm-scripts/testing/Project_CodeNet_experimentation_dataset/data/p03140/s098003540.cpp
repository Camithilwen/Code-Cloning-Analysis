#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int N, ans = 0;
    string A, B, C;
    cin >> N >> A >> B >> C;
    for (int i = 0; i < N; i++){
        set<char> T;
        T.insert(A.at(i));
        T.insert(B.at(i));
        T.insert(C.at(i));
        if (T.size() == 2){
            ans++;
        }
        else if (T.size() == 3){
            ans += 2;
        }
    }
    cout << ans << endl;
}

