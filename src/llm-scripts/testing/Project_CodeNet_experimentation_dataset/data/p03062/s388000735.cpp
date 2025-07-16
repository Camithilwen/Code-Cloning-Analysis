#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  int64_t Z=0,MIN=167167167167617,A=1;
  for(int i=0;i<N;i++){
    int64_t a;
    cin>>a;
    if(a<0){
      A*=-1;
      a*=-1;
    }
    Z+=a;
    MIN=min(MIN,a);
  }
  cout<<Z-MIN+A*MIN<<endl;
}

