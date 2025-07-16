#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool vanmo = false;
  while(n > 0){
    if(n % 10 == 7){
      vanmo = true;
    }
    n = n / 10;
  }
  if(vanmo){
    cout << "Yes";
  }else{
    cout << "No";
  }
	return 0;
}
