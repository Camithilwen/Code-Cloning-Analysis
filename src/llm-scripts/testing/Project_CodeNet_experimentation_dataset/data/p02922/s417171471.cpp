#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long

    int main (){
        int a,b;
        cin >> a >> b;
        int i=0;
        int sum = 1;
  while(sum<b){
      sum--;
      sum+=a;
    i++;
  }
        cout << i << endl;
        return 0;
    }