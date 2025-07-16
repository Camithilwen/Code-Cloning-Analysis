#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w,a,b;
  cin>>h>>w>>a>>b;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if((j<a && i<b) || (j>=a && i>=b)) cout<<0;
      else cout<<1;
      if(j==w-1) cout<<endl;
    }
  }
}
