#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int K, X; cin >> K >> X;
    int now = X-K+1;
    while(now <= X+K-1){
        cout << now << endl;
        now++;
    }

    return 0;
}