#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,k,L[100];
  cin >> n >> k;
  for(int i = 0; i < n; i++) 
    cin >> L[i];
  
  sort(L,L+n);
  int sum = 0;
  for(int i = n-1; i >= n-k; i--)
    sum += L[i];

  cout << sum << endl;
}