#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  long long num, max, a, b=0;
  cin >> num >> max;
  vector<long long> list2;
  for (long long i=0; i<num; i++) {cin >> a; list2.push_back(a);}
  sort(list2.begin(),list2.end());
  reverse(list2.begin(),list2.end());
  for (long long i=0; i<max; i++) {b+=list2[i];}
  cout << b;}