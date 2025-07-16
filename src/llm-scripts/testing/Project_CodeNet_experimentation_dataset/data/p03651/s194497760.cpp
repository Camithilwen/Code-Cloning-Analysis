#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int gcd(int a,int b){
  if(b==0){
    return a;
  }
  return gcd(b,a%b);
}
int main(){
  int n,k,a[100010],i;
  cin >> n >> k;
  int z=0;
  for(i=0;i<n;i++){
    cin >> a[i];
    if(a[i]>=k){
      z=1;
    }
  }
  if(z==0){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  if(n==1){
    if(a[0]==k){
      cout << "POSSIBLE" << endl;
    }
    else{
      cout << "IMPOSSIBLE" << endl;
    }
    return 0;
  }
  int x=gcd(a[0],a[1]);
  for(i=2;i<n;i++){
    x=gcd(x,a[i]);
  }
  if(k%x==0){
    cout << "POSSIBLE" << endl;
  }
  else{
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}