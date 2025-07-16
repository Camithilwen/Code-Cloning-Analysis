#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
vector<string> vec{"SUN","MON","TUE","WED","THU","FRI","SAT"};
  string S;
  cin>>S;
  for(ll i=0;i<7;i++) {
    if(S==vec[i]) {
cout<<7-i<<endl;
    }
  }
}