#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  vector<int> a(5);
  rep(i, 5) cin >> a[i];

  int k;
  cin >> k;

  for (int i = 0; i < 5;i ++){
    for (int j = i+1; j < 5; j++){
      if(abs(a.at(i)-a.at(j)) >k){
        cout << ":(";
            return 0;
      }
    }
  }
  cout << "Yay!";
}
