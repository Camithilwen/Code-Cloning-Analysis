#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  
  if(n < 10){
    cout << m + (10 - n)*100 << endl;
  }else{
    cout << m << endl;
  }
}