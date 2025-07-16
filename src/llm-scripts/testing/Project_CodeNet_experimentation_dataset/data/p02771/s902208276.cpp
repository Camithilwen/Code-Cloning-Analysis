#include<bits/stdc++.h>
using namespace std;

vector<pair<long long,long long>> bunkai;

int main(){
  int a,b,c; cin >> a >> b >> c;
  if(a == b && b == c && c == a || a != b && b != c && c != a)
    cout << "No";
  else
    cout << "Yes";
}
  