
#include<bits/stdc++.h>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


using namespace std;

int N;
string S;
long long m, c, t;

void add(int i) {
    if (S[i] == 'M') ++m;
    else if (S[i] == 'C') ++c, t += m;
}

void erase(int i) {
    if (S[i] == 'M') --m, t -= c;
    else if (S[i] == 'C') --c;
}

long long solve(int K) {
    long long res = 0;
    m = 0; t = 0;
    int r = 0;
    for (int l = 0; l < N;) {
        while(r < N && r - l <K) add(r++);
        if (S[l] == 'D') res += t;
        erase(l++);
    }
    return res;
}

int main(){
    while (cin >> N >> S) {
        int Q; cin >> Q;
        for (int i = 0; i < Q; ++i) {
            int k; cin >> k;
            cout << solve(k) << endl;
        }
    }
}
