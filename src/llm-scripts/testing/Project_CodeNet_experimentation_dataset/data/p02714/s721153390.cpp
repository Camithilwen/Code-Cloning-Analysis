#include <bits/stdc++.h>
// clang-format off
using namespace std; using ll = int64_t; using ull = uint64_t; const ll INF = 9e18;
void print() { cout << endl; }
template<typename Head,typename... Tail> void print(Head head,Tail... tail){cout<<head;if(sizeof...(Tail)>0)cout<<" ";print(tail...);}
void print0() {}
template<typename Head,typename... Tail> void print0(Head head,Tail... tail){cout<<head;print0(tail...);}
// clang-format on

int main() {
    ll N;
    cin >> N;
    string S;
    getline(cin, S);
    getline(cin, S);

    vector<ll> R;
    vector<ll> G;
    vector<ll> B;
    set<ll> RS;
    set<ll> GS;
    set<ll> BS;
    for (ll i = 0; i < S.length(); i++) {
        char c = S.at(i);
        if (c == 'R') {
            R.push_back(i);
            RS.insert(i);
        } else if (c == 'G') {
            G.push_back(i);
            GS.insert(i);
        } else {
            B.push_back(i);
            BS.insert(i);
        }
    }

    ll total = 0;
    // ll tpre = 0;
    for (ll i = 0; i < S.length(); i++) {
        char ci = S.at(i);
        for (ll j = i + 1; j < S.length(); j++) {
            char cj = S.at(j);
            ll notk = j + j - i;
            if (ci == 'R') {
                if (cj == 'G') {
                    total += B.end() - lower_bound(B.begin(), B.end(), j) - BS.count(notk);
                } else if (cj == 'B') {
                    total += G.end() - lower_bound(G.begin(), G.end(), j) - GS.count(notk);
                }
            } else if (ci == 'G') {
                if (cj == 'R') {
                    total += B.end() - lower_bound(B.begin(), B.end(), j) - BS.count(notk);
                } else if (cj == 'B') {
                    total += R.end() - lower_bound(R.begin(), R.end(), j) - RS.count(notk);
                }
            } else if (ci == 'B') {
                if (cj == 'R') {
                    total += G.end() - lower_bound(G.begin(), G.end(), j) - GS.count(notk);
                } else if (cj == 'G') {
                    total += R.end() - lower_bound(R.begin(), R.end(), j) - RS.count(notk);
                }
            }
            // if (tpre != total) {
            //     print(i, j, total - tpre);
            // }
            // tpre = total;
        }
    }
    print(total);
}
