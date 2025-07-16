#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,l;
  cin >> n >> l;
  
  int a[n];
  int all = 0;
  for(int i = 1; i <= n; i++){
    a[i] = l + i - 1;
    all += a[i];
  }
  
  int minu = 0,maxmin = 2000000;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(j != i){
        minu += a[j];
      }//if
    }//for
    if(abs(minu - all) < abs(maxmin - all)){
      maxmin = minu;
    }
    minu = 0;
  }
  
  cout << maxmin << endl;
    
}