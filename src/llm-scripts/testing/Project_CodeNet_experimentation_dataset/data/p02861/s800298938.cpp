#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
  double ans = 0;
  int count = 0;
  int N;
  cin >> N;
  vector<pair<int, int>> points;
  for(int i=0;i<N;i++){
    pair<int, int> p;
    cin >> p.first;
    cin >> p.second;
    points.push_back(p);
  }
  sort(points.begin(), points.end());
  do{
    int sx = points[0].first;
    int sy = points[0].second;
    for(int i=1; i<N; i++){
      ans += sqrt(pow((sx-points[i].first), 2) + pow((sy-points[i].second), 2));
      sx = points[i].first;
      sy = points[i].second;
    }
    count++;
  }while(next_permutation(points.begin(), points.end()));
  cout << setprecision(10) << (double)ans/count << endl;
  return 0;
}