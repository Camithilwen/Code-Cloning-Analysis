#include <bits/stdc++.h>
using namespace std;
void print() {
    cout << endl;
}
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
    cout << head;
    if (sizeof...(tail) != 0)
        cout << " ";
    print(forward<Tail>(tail)...);
}
template <class T>
void print(vector<T> &vec) {
    for (auto &a : vec) {
        cout << a;
        if (&a != &vec.back())
            cout << " ";
    }
    cout << endl;
}
template <class T>
void print(vector<vector<T>> &df) {
    for (auto &vec : df) {
        print(vec);
    }
}
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define xrep(i, a, b) for (int i = int(a); i < int(b); ++i)
using ll = long long;
const int INF = 1001001001;



int bills[3] = {10000, 5000, 1000};

int main() {
    int N, Y;
    cin >> N >> Y;


    rep(i, N+1) {
        rep(j, N+1) {
            int k = N-(j+i);
            if(k<0) continue;
            if(bills[0]*i+bills[1]*j+bills[2]*k==Y) {
                print(i, j, k);
                return 0;
            }
        }
    }

    print(-1, -1, -1);


    return 0;
}