#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<iomanip>
#define pi 3.14159265358979323846
#define ll long long
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  string s;
  cin >> s;
  if(s == "RRR"){
    cout << "3\n";
    return 0;
  }
  if(s == "RRS" || s == "SRR"){
    cout << "2\n";
    return 0;
  }
  if(s == "SSS"){
    cout << "0\n";
    return 0;
  }
  cout << "1\n";
  return 0;
}