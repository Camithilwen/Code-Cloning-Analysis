#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int x,y,z;
  cin>>x>>y>>z;
  int temp = x;
  x = y;
  y = temp;
  int temp2 = x;
  x = z;
  z = temp2;
  cout<<x<<" "<<y<<" "<<z;
  return 0;
}