#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  int a,b,ans=0;
  cin >> a >> b;
  for(int i = a;i<b+1;i++){
   if(i/10000==i%10&&(i/1000-(i/10000)*10)==(i%100-i%10)/10)ans++;
  }
  cout << ans;
}