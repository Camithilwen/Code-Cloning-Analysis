#include <bits/stdc++.h>
using namespace std;

int main(){
  string N,m;
  cin >> N;
  int x,y = 0;
  for(int i = 0; i < int(N.size()); i++){
    istringstream n;
    m = N[i];
  	n = istringstream(m);
  	n >> x;
    y += x;
  }
  if (stoi(N) % y == 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
