#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string s;
  cin >> s;
  int n = s.size();

  int mn = 754;
  for(int i=0; i<n-2; ++i){
    string str = s.substr(i,3);
    int num = stoi(str);
    int res = abs(num-753);
    mn = min(mn, res);
  }
  cout << mn;
}  
