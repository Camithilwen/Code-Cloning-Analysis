#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    vector<int> antenna (5);
    REP(i,5){
        cin >> antenna[i];
    }
    int k;
    cin >> k;
    REP(i,4){
        FOR(j,i,5){
            if (antenna[j] - antenna[i] > k){
                cout << ":(" << endl;
                return 0;
            }
        }
    }
    cout << "Yay!" << endl;
    return 0;
}