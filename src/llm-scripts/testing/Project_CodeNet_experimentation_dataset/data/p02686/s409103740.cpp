#include<functional>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<string> S(N);
    for (auto& s : S) {
        cin >> s;
    }
    vector<P> pos, neg;
    for (auto& s : S) {
        string now;
        for (auto& c : s) {
            if (now.empty()) {
                now += c;
            } else {
                if (now.back() == '(' && c == ')') {
                    now.pop_back();
                } else {
                    now += c;
                }
            }
        }
        int A = 0, B = 0;
        for (auto& c : now) {
            if (c == ')') {
                ++A;
            } else {
                ++B;
            }
        }
        if (B - A >= 0) {
            pos.emplace_back(A, B);
        } else {
            neg.emplace_back(A, B);
        }
    }
    sort(all(pos), [](P a, P b) {
        return a.first < b.first;
    });
    int cumsum = 0;
    for (auto& p : pos) {
        cumsum -= p.first;
        if (cumsum < 0) {
            cout << "No" << endl;
            return 0;
        }
        cumsum += p.second;
    }
    sort(all(neg), [](P a, P b) {
        return a.second > b.second;
    });
    for (auto& p : neg) {
        cumsum -= p.first;
        if (cumsum < 0) {
            cout << "No" << endl;
            return 0;
        }
        cumsum += p.second;
    }
    if (cumsum) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}