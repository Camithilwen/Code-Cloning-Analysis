#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a[5];
  int ans;
  for(int i=0;i<2;i++){
    cin>>a[i];
  }
  sort(a,a+2);
  ans=a[1];
  a[1]--;
  sort(a,a+2);
  ans+=a[1];
  cout<<ans<<"\n";
  return 0;
}