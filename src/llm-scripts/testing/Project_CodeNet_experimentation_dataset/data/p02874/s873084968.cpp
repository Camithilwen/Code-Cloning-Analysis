#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) {
  return '"' + s + '"';
}
string to_string(const char* s) {
  return to_string((string) s);
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
const long long mod = 1e9+7; // CHECK
long long power(long long a, long long b, long long m = mod) {
    if(b < 0) {
        return power(power(a, -b), mod-2);
    }
    long long x = 1;
    while(b) {
        if(b & 1) {
            x = 1ll * x * a % m;
        }
        a = 1ll * a * a % m;
        b /= 2;
    }
    return x;
}
#define ll long long
const int INT_INF = 1e9+9;
const ll LL_INF = 2e18;
const int N = 3e5+9;

signed main() {  
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int latest_start = 0, earliest_finish = 0;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        if (a[latest_start].first < a[i].first) {
            latest_start = i;
        } 
        if (a[earliest_finish].second > a[i].second) {
            earliest_finish = i;
        }
    }
    int ans = 0;
    // both in same
    {
        int longest = -INT_INF;
        for (int i = 0; i < n; i++) {
            if (i == earliest_finish || i == latest_start) continue;
            longest = max(longest, a[i].second - a[i].first + 1);
        }
        ans = max(ans, longest + max(a[earliest_finish].second - a[latest_start].first + 1, 0));
    }
    // earliest_finish in left 
    {
        vector<pair<int, int>> b;
        for (int i = 0; i < n; i++) {
            if (i == earliest_finish || i == latest_start) continue;
            b.push_back({max(0, a[earliest_finish].second - a[i].first + 1),
                -max(0, a[i].second - a[latest_start].first + 1)});
        }
        sort(b.begin(), b.end());
        int mn_right = a[latest_start].second - a[latest_start].first + 1;
        for (int i = 0; i < n-2; i++) {
            ans = max(ans, b[i].first + mn_right);
            mn_right = min(mn_right, -b[i].second);
        }
        ans = max(ans, mn_right + a[earliest_finish].second - a[earliest_finish].first + 1);
    }
    cout << ans << '\n';


    

    return 0;
}

