#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b;
  cin>>a>>b;
  if(a<9 && b<9){
    cout<<"Yay!"<<"\n";
  }
  else{
    cout<<":("<<"\n";
  }
  return 0;
}