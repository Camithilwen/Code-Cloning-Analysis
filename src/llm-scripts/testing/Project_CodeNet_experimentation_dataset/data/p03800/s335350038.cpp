#include <bits/stdc++.h>
#include <limits>
#include <math.h>
#include <cmath>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vvi = vector<vector<int>> ;
using vll = vector<long long>;
using vvll = vector<vector<long long >>;
#define PI 3.141592653
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
  int n; cin >> n;
  string s; cin >> s;
  bool fin;
  if(s[0] == 'o'){fin = true;}
  else{fin = false;}
  bool ans = true;
  

  vector<char> s1(n+1);
  s1[0] = 'W'; s1[1] = 'S';
  vector<char> s2(n+1);
  s2[0] = 'W'; s2[1] = 'W';
  vector<char> s3(n+1);
  s3[0] = 'S'; s3[1] = 'S';
  vector<char> s4(n+1);
  s4[0] = 'S'; s4[1] = 'W';

  while(true){
  bool f;
  for(int i = 2; i <= n; i++){
    f = true;
    if(s1[i-2] == 'W'){f = !f;}
    if(s1[i-1] == 'W'){f = !f;}
    if(s[i-1] == 'x'){f = !f;}
    if(f){s1[i] = 'S';}
    else{s1[i] = 'W';}
  }
  if(fin){if(s1[n-1] == 'W' && s1[0] == s1[n])  {rep(i, n){cout << s1[i];}ans = false; break;}}
  else{if(s1[n-1] == 'S' && s1[0] == s1[n])  {rep(i, n){cout << s1[i];}ans = false; break;}}
  for(int i = 2; i <= n; i++){
    f = true;
    if(s2[i-2] == 'W'){f = !f;}
    if(s2[i-1] == 'W'){f = !f;}
    if(s[i-1] == 'x'){f = !f;}
    if(f){s2[i] = 'S';}
    else{s2[i] = 'W';}
  }
  if(fin){if(s2[n-1] == 'S' && s2[0] == s2[n] ) {rep(i, n){cout << s2[i];}ans = false; break;}}
  else{if(s2[n-1] == 'W' && s2[0] == s2[n])  {rep(i, n){cout << s2[i];}ans = false; break;}}

  for(int i = 2; i <= n; i++){
    f = true;
    if(s3[i-2] == 'W'){f = !f;}
    if(s3[i-1] == 'W'){f = !f;}
    if(s[i-1] == 'x'){f = !f;}
    if(f){s3[i] = 'S';}
    else{s3[i] = 'W';}
  }
  if(fin){if(s3[n-1] == 'S' && s3[0] == s3[n]) {rep(i, n){cout << s3[i];} ans = false; break;}}
  else{if(s3[n-1] == 'W' && s3[0] == s3[n])  {rep(i, n){cout << s3[i];}ans = false;  break;}}

  for(int i = 2; i <= n; i++){
    f = true;
    if(s4[i-2] == 'W'){f = !f;}
    if(s4[i-1] == 'W'){f = !f;}
    if(s[i-1] == 'x'){f = !f;}
    if(f){s4[i] = 'S';}
    else{s4[i] = 'W';}
  }
  if(fin){if(s4[n-1] == 'W'  && s4[0] == s4[n])  {rep(i, n){cout << s4[i];} ans = false;break;}}
  else{if(s4[n-1] == 'S' && s4[0] == s4[n]) { rep(i, n){cout << s4[i];}ans = false; break;}}

  cout << -1;
  break;
  }
  cout << endl;
}       