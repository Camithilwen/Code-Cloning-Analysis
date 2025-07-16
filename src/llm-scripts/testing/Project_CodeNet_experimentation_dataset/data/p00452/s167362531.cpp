#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> a;
vector <int> all;
int n,m;


int main() {

  while(1) {
    scanf("%d%d",&n,&m);
    if(n == 0 && m ==0) break;
    a.resize(n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    a.push_back(0);
    all.clear();

    for(int i=0;i<a.size();i++) 
      for(int j=i;j<a.size();j++)
	all.push_back(a[i]+a[j]);

    sort(all.begin(),all.end());

    int ans = 0;
    int allsize = all.size();
    int b = 0;
    for(int i=allsize-1;i>= 0;i--) {
      for(int j=b;j<allsize;j++) {
	int sum = all[i] + all[j];
	if(sum > m) break;
	b++;
	if(ans < sum) ans = sum;
      }
      if(ans == m) break;
    }

    cout << ans <<endl;
  }
  return 0;
  
}