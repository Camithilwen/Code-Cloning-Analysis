#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define pi 3.14159265358979323846
#define ll long long
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int n, sm = 0;
  cin >> n;
  if(n >= 500){
    sm += n / 500 * 1000;
    n = n % 500;
  }
  if(n >= 5){
    sm += n / 5 * 5;
  }
  
  cout << sm << "\n";
}