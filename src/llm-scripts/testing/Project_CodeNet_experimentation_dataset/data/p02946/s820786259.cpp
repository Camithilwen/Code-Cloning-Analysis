#include<bits/stdc++.h>
using namespace std;

int main(){
  int k,x;
  cin >> k >> x;
  for(int i = x-k+1; i <= x + k - 2; i++){
    cout << i << " ";
  }
  cout << x + k - 1 << endl;
}