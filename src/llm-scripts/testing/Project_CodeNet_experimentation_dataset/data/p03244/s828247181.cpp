#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;  cin >> n;
  int table[2][100005] = {0};    

  for(int i=0; i<n; i++){
    int v;  cin >> v;
    table[i%2][v]++;
  }

  vector<pair<int, int>> ruia, ruib;
  for(int i=0; i<1e5+5; i++){
    if(table[0][i])  ruia.push_back({table[0][i], i});
    if(table[1][i])  ruib.push_back({table[1][i], i});
  }
  sort(ruia.rbegin(), ruia.rend());
  sort(ruib.rbegin(), ruib.rend());

  long ans = 0;
  if(ruia[0].second == ruib[0].second){
    if(ruia.size() == 1 && ruib.size() == 1)
      ans = n / 2;
    else if(ruia.size() == 1)
      ans = n/2 - ruib[1].first;
    else if(ruib.size() == 1)
      ans = n/2 - ruia[1].first;
    else
      ans = min(n/2-ruib[0].first+n/2-ruia[1].first, n/2-ruia[0].first+n/2-ruib[1].first);
  }else{
    ans = n/2-ruia[0].first + n/2-ruib[0].first;
  }

  cout << ans << endl;

  return 0;
}
