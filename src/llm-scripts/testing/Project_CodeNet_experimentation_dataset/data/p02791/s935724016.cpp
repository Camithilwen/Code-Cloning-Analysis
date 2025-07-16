#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,cnt=0;
  cin >> n;
  int p[n],m=(1<<30);
  for(int i=0;i<n;i++){
    cin >> p[i];
    if(m>p[i]){
      cnt++;
      m=min(m,p[i]);
    }
  }
  cout << cnt << endl;
}
