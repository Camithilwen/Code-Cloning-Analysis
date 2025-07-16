#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;



template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

int main() {
    int N; cin >> N;
    vector<int> A;
    A.emplace_back(1e9 + 100);
    while(N--) {
        int a; cin >> a;
        if(a <= *(A.end()-1)) A.emplace_back(a);
        else {
            
            int ok = int(A.size());
            int ng = -1;
            while(abs(ok - ng) > 1) {
                int x = (ok + ng) / 2;
                if(A.at(x) < a) ok = x;
                else ng = x;
            }
            A.at(ok) = a;
        }
    }
    cout << A.size() - 1 << endl;
    return 0; 
}