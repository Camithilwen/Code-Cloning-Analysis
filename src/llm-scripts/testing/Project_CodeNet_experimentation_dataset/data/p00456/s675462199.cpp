//32
#include<iostream>
#include<algorithm>
#include<numeric>
#include<functional>

using namespace std;

int main(){
  int p[2][10];
  for(int i=0;i<2;i++){
    for(int j=0;j<10;j++){
      cin>>p[i][j];
    }
  }
  for(int i=0;i<2;i++){
    sort(p[i],p[i+1],greater<int>());
    cout<<accumulate(p[i],p[i]+3,0)<<((i==0)?' ':'\n');
  }
  return 0;
}