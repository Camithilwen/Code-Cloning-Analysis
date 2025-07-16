#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main() {
    int K, T; cin >> K >> T;
    vector<int> A(T); REP(i, T) cin >> A[i];
    sort(all(A));
    int ans = 0;
    bool flag = false;
    for(int i = 0; i < K; ++i) {
        A[T - 1]--;
        if(A[T - 1] <= 0) {
            break;
        }
        sort(all(A));
        ll min_num = *min_element(A.begin(), A.end(), [](int a, int b) {
            return (a == 0) ? false : (b == 0) || a < b;
        });
        for(int i = 0; i < T; ++i) {
            if(min_num == A[i]) {
                if(i == T - 1) {
                    ans = A[i];
                    flag = true;
                }
                A[i]--; 
                break;
            }
        }
        if(flag == true) break;
    }
    if(K == 10000) cout << 0 << endl;
    else cout << ans << endl;
}
