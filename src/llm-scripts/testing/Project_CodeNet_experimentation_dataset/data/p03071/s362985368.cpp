#include <bits/stdc++.h>
using namespace std;

int main(){
  	int a,b;
  cin >> a >> b;
  cout << max((2*max(a,b))-1, a+b) << endl;
  return 0;
}