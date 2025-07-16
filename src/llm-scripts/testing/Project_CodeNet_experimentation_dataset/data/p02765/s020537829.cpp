#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
  int n, r;
  cin >> n >> r;
  if(n<10){
   cout << r - 100*n + 1000 << endl;
  }else{
    cout << r << endl;
  }
}

