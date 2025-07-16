#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const int MOD = 1000000007;
int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  ll k;
  cin >> k;
  int n = 50;
  ll x = (k + n*n - n) / n;
  ll arr[50];
  for(int i = 0;i < 50;i++){
    arr[i] = x;
  }
  ll rem = k - (x * n - n*n + n);
  for(int i = 0;i < rem;i++){
    arr[i] += n;
    for(int j = 0;j < 50;j++){
      if(i != j)
        arr[j]--;
    }
  }
  cout << 50 << endl;
  for(int i = 0;i < n;i++)
    cout << arr[i] << ' ';
}

