#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main(){
  vector <int> dp(8000);
  rep(i, 8000) dp[i] = 0;
  int N, T; cin >> N >> T;
  vector<pair <int, int>>AB;
  rep(i, N){
    int a, b; cin >> a >> b;
    AB.push_back(make_pair(a, b));
  }
  sort(AB.begin(), AB.end());
  
  rep(i,  N){
    vector <int> temp;
    copy(dp.begin(), dp.end(), back_inserter(temp));
    rep(t, T){
      dp[t + AB[i].first] = max(temp[t + AB[i].first], temp[t] + AB[i].second);
    }
  }
  int ans = *max_element(dp.begin(), dp.end());
  cout << ans <<endl;
}