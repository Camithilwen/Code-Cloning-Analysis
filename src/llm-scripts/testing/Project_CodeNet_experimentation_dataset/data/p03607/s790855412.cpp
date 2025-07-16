#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

main(){
  int n;cin >> n;
  int a[n];for(int i=0;i<n;i++)cin >> a[i];
  sort(a,a+n);
  int ans=0;
  for(int i=0;i<n;){
    int cc = a[i];
    int cnt = 0;
    int j=i;
    while(a[j] == cc){
        cnt++;
        i++;
        j++;
      }
    ans+=cnt%2;
  }
  cout << ans << endl;
  return 0;
} 