#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
#include<deque>
#include<list>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int a[5],i,j;
  for(i=0;i<3;i++){
    cin >> a[i];
  }
  int ans=(1<<29);
  for(i=0;i<3;i++){
    for(j=i+1;j<3;j++){
      ans=min(ans,a[i]+a[j]);
    }
  }
  cout << ans << endl;
  return 0;
}