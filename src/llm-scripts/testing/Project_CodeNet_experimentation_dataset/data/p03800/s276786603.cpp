#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

vector<char> ans(100100, '.');
int n;
string s;

void swcheck(vector<char> &sw) {
    for(int i = 1; i < n; ++i) {
        if(s.at(i) == 'o') {
            if(sw.at(i) == 'S') {
                if(sw.at(i-1) == 'S') sw.at(i+1) = 'S';
                else sw.at(i+1) = 'W';
            }else {
                if(sw.at(i-1) == 'S') sw.at(i+1) = 'W';
                else sw.at(i+1) = 'S';
            }
        }else {
            if(sw.at(i) == 'S') {
                if(sw.at(i-1) == 'S') sw.at(i+1) = 'W';
                else sw.at(i+1) = 'S';
            }else {
                if(sw.at(i-1) == 'S') sw.at(i+1) = 'S';
                else sw.at(i+1) = 'W';
            }
        }
    }
}

bool lacheck(vector<char> &sw) {
    if(sw.at(0) == sw.at(n)) {
        if(s.at(0) == 'o') {
            if(sw.at(0) == 'S') {
                if(sw.at(n-1) == sw.at(1)) return true;
            }else {
                if(sw.at(n-1) != sw.at(1)) return true;
            }
        }else {
            if(sw.at(0) == 'S') {
                if(sw.at(n-1) != sw.at(1)) return true;
            }else {
                if(sw.at(n-1) == sw.at(1)) return true;
            }
        }
    }
    return false;
}

void swprint(vector<char> &sw) {
    for(int i = 0; i < n; ++i) {
        if(i == n-1) cout << sw.at(i) << endl;
        else cout << sw.at(i);
    }
}

int main() {
    cin >> n >> s;
    ans.at(0) = 'S'; ans.at(1) = 'S';
    swcheck(ans);
    if(lacheck(ans)) {
        swprint(ans); return 0;
    }
    ans.at(0) = 'S'; ans.at(1) = 'W';
    swcheck(ans);
    if(lacheck(ans)) {
        swprint(ans); return 0;
    }
    ans.at(0) = 'W'; ans.at(1) = 'S';
    swcheck(ans);
    if(lacheck(ans)) {
        swprint(ans); return 0;
    }
    ans.at(0) = 'W'; ans.at(1) = 'W';
    swcheck(ans);
    if(lacheck(ans)) {
        swprint(ans); return 0;
    }
    cout << -1 << endl;
}