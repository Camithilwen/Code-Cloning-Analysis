#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a[5],b[5];
  int ans=0;
  cin>>a[0]>>a[1]>>b[0]>>b[1];
  sort(a,a+2);
  sort(b,b+2);
  ans=a[0]+b[0];
  cout<<ans<<"\n";
  
  return 0;
}