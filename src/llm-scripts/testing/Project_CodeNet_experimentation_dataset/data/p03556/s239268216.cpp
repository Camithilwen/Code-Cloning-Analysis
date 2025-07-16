#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int s=0,i=0;
  while(s<=n){
    i++;
    s=i*i;
  }
  i--;
  cout << i*i << endl;
}