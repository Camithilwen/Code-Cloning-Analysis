#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t M,a=0,b=0;
  cin>>M;
  for(int64_t i=0;i<M;i++){
    int64_t x,y;
    cin>>x>>y;
    a+=x*y;
    b+=y;
  }
  cout<<(a-1)/9+b-1<<endl;
}