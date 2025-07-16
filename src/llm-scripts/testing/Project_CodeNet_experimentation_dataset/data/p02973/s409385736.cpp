#include<bits/stdc++.h>
using namespace std;
using ll=long long;



int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;++i) cin >> a[i];

  multiset<int> ms;
  for(int i=0;i<n;++i){
    int s=a[i];
    auto itr=ms.lower_bound(s);
    if(itr!=ms.begin())ms.erase(--itr);
    ms.insert(s);
  }

  cout << ms.size() << endl;
  return 0;
}
