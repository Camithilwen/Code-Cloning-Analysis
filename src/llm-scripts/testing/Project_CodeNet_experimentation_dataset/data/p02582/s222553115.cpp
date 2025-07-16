#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int ans =0;
  if(s == "RRR"){ans = 3;}
  if(s == "RRS"){ans = 2;}
  if(s == "RSR"){ans = 1;}
  if(s == "SRR"){ans = 2;}
  if(s == "RSS"){ans = 1;}
  if(s == "SRS"){ans = 1;}
  if(s == "SSR"){ans = 1;}
  if(s == "SSS"){ans = 0;}
  cout << ans << endl;
}