#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<pair<int,int>> v;
  for(int i = 1; i <= n; i++){
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
  }
  int result = 0;
  for(int i = 1; i < v.size(); i++)
    if(v[i].second < v[0].second)
      swap(v[0], v[i]);
  sort(v.begin() + 1, v.end());

  for(int i = 0; i < v.size(); i++)
    result = max(result, v[i].second - v[i].first + 1);

  for(int i = 1;i < v.size() - 1; i++)
    result = max(result, (v[i].second - v[i].first + 1) + (v[0].second - max(v[0].first, v.back().first) + 1));


  int minr = v.back().second;
  for(int i = v.size() - 1; 1 <= i; i--){
    minr = min(minr, v[i].second);
    result = max(result, (minr - v.back().first + 1) + (v[0].second - max(v[0].first, v[i - 1].first) + 1));
  }
  cout << result;
  return 0;
}
