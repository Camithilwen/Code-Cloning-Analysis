#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N + 2, 0);
    int sum = 0;
    rep(i, 1, N + 1) cin >> A.at(i);
    rep(i, 0, N + 1) sum += abs(A.at(i + 1) - A.at(i));
    rep(i, 1, N + 1){
        int x = A.at(i - 1);
        int y = A.at(i);
        int z = A.at(i + 1);
        if ((x - y)*(y - z) >= 0){
            cout << sum << endl;
        }
        else{
            cout << sum - 2 * min(abs(x - y), abs(y - z)) << endl;
        }
    }
}
