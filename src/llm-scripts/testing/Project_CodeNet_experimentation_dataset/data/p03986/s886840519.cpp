#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
const int INF=1001001001;

int main() {
  string s;
  cin>>s;
  int n=s.size();
  int stack=0,e=0;
  for(int i=0;i<n;i++){
    if(s[i]=='S'){stack++;}
    else if(stack>0){stack--;e++;}
  }
  cout<<n-2*e<<endl;
  return 0;
}