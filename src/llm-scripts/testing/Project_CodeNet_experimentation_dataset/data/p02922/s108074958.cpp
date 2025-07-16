#include<bits/stdc++.h>
using namespace std;

int main(){
  int sum = 1, a, b, i = 0; cin >> a >> b;
  while(sum < b){
    sum = sum - 1 + a;
    i++;
  }
  cout << i << endl;
}  