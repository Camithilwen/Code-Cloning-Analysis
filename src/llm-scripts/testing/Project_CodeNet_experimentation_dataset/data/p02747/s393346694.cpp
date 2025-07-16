#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
string s;
cin >> s;
bool ans = true;
rep(i,s.size()){
  if(s.size()%2!=0){
    ans = false;
    break;
  }
  if(s.at(i)!='h' || s.at(i+1)!='i') ans = false;
  i++;
  
}
cout << (ans?"Yes":"No") << endl;
}
