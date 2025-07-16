#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
const int INF=1001001001;

int main() {
  int64_t N;
  cin>>N;
  int x=N;
  string t;
  while(x){
   int r=x%(-2);
   if(r<0){r+=2;}
   x-=r;
   x/=(-2);
   t+=(char)('0'+r);
  }
  reverse(t.begin(),t.end());
  if(t==""){t='0';}
  cout<<t<<endl;
  return 0;
}