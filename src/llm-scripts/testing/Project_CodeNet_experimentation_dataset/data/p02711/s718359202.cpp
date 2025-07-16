#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  if(n%10==7||n/10%10==7||n/100%10==7) cout<<"Yes"; else cout<<"No";
  return 0;
}