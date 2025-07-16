#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;

const long INF = 1e9 + 1;

int main() {
  int n,m,X,Y,x[200],y[200];
  cin >> n >> m >> X >> Y;
  for(int i = 0; i < n; i++)
    cin >> x[i];
  for(int i = 0; i < m; i++)
    cin >> y[i];
  
  sort(x,x+n); sort(y,y+m);

  if(x[n-1] < y[0] & X < y[0] & x[n-1] < Y)
    cout << "No War" << endl;
  else 
    cout << "War" << endl;
}