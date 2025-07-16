#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}

ll INF = 1e+18;
int iINF = 1e9;
int MAXI = 1e8 + 1;
using vec = vector<int>;

int 
main()
{
  int N; cin >> N;
  vec arr(N + 1);
  repe(i, 1, N) cin >> arr[i];
  vec ball(N + 1, 0);
  int num = 0;

  for(int i = N; i >= 1; --i){
    int val = i;
    int cnt = 0;
    while(true){
      val += i;
      if(val > N) break;
      if(ball[val] == 1) ++cnt;
    }
    if(arr[i] != (cnt % 2)) ball[i] = 1, ++num;
  }
  cout << num << endl;
  rep(i, 1, N + 1){
    if(ball[i] == 1) cout << i << " ";
  }
}
