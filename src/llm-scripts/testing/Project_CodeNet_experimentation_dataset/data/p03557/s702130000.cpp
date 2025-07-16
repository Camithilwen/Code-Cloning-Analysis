#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef vector<lint> vlint;
typedef vector<vlint> vvlint;
typedef vector<bool> vbool;
typedef vector<int> vint;


#define inf 1e+9
#define endl "\n"
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define rep_rev(i, n) for (int i = n-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()

#define pb push_back
#define eb emplace_back
#define Size(c) (int)(c).size()

#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))

template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

template <class T, class S> inline bool chmax(T &a, S b) {
    if(a < b) {a = b;return 1;} return 0;
}
template <class T, class S> inline bool chmin(T &a, S b) {
    if(a > b) {a = b;return 1;} return 0;
}
template <class T>
void line(vector<T> &x){for (auto&& xi : x) cin >> xi;}

inline void IN(void){ return;}

template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){ cin >> first; IN(rest...); return;}

#define INT(...) int __VA_ARGS__; IN (__VA_ARGS__)
#define LINT(...) lint __VA_ARGS__; IN (__VA_ARGS__)
#define STR(...) string __VA_ARGS__; IN(__VA_ARGS__)

template <class T> void UNIQUE(vector<T> &x) {
    sort(all(x)); x.erase(unique(all(x)), x.end());
}
template <class T> void print_vec(T first, T end){
    for (auto i = first; i < end - 1; i++) cout << *i << " ";
    cout << *(end-1) << endl;
}

template<class... T>
void debug_print(T... args){
    vector<lint> tmp = initializer_list<lint>{args...};
    print_vec(all(tmp));
}
template<class T>
void print(T a){ cout << a << endl;}

vector<string> Yes = {"No", "Yes"};
vector<string> YES = {"NO", "YES"};

int ord(char x){ return (int)(x - 'a');}
char chr(lint x){ return (char)(x + (lint)('a'));}
lint mod = 1e9+7;
// lint mod = 

lint sum(vlint a){lint ret = 0; for(auto&& v:a) ret += v; return ret;}
lint vmini(vlint a, lint &index){
    lint ret = LLONG_MAX;
    rep(i, Size(a)){ if (chmin(ret, a[i])) index = i;}
    return ret;
}
lint vmaxi(vlint a, lint &index){
    lint ret = -LLONG_MAX;
    rep(i, Size(a)){ if (chmax(ret, a[i])) index = i;}
    return ret;
}

lint vmin(vlint a){
    lint ret = LLONG_MAX; for (auto && v : a) chmin(ret, v); return ret;
}
lint vmax(vlint a){
    lint ret = -LLONG_MAX; for (auto && v : a) chmax(ret, v); return ret;
}


vlint base_3(int k){
    vlint ret; while (k > 0){ ret.pb(k % 3); k /= 3;} reverse(all(ret)); return ret;
}
map<lint, lint> trial_division(lint n){
    map<lint, lint> factor;
    lint tmp = (lint)(sqrt(n)) + 1;
    for (lint i = 2; i < tmp; ++i){
        while (n % i == 0){
            n /= i;
            factor[i] ++;
        }
    }
    if(n != 1) factor[n] ++;
    return factor;
}
bool judge(lint u){
    return 0 <= u && u <= 5000;
}
lint dist(lint x1, lint y1, lint x2, lint y2){
    return (x1-x2) * (x1-x2) + (y1-y2) * (y1 - y2);
}



int main(){
    LINT(n);
    vlint a(n), b(n), c(n);
    line(a); line(b); line(c);

    sort(all(a)); sort(all(c));
    lint u, d; lint ans = 0;
    rep(i, n){
        u = lb(a, b[i]);
        d = n - ub(c, b[i]);
        ans += u * d;
    }
    print(ans);

}
