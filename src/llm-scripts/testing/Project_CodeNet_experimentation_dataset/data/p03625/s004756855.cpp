#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int MOD = 1000000007;
using pint = pair<ll, ll>;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> out;
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end());
    ll cnt = 1;
    for (int i = 0; i < N-1; i++) {
      if (A[i] == A[i + 1]) {
        cnt++;
      }
      else{
          if(cnt/2==1){
            out.push_back(A[i]);
          }
          else if(cnt/2>=2){
            out.push_back(A[i]);
            out.push_back(A[i]);
          }
          cnt = 1;
      }
    }
    if (cnt / 2 == 1) {
      out.push_back(A[A.size()-1]);
    } else if (cnt / 2 >= 2) {
      out.push_back(A[A.size()-1]);
      out.push_back(A[A.size()-1]);
    }
    if (out.size() < 2)
      cout << 0 << endl;
    else
      cout << out[out.size() - 1] * out[out.size() - 2] << endl;
    return 0;
}