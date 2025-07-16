#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
  if(x%y==0) return y;
  else return gcd(y,x%y);
}
int main(){
  int n,i,k,a,G,MAX;scanf("%d%d",&n,&k);
  scanf("%d",&G);MAX = G;
  if(n == 1){
    printf((k==G) ? "POSSIBLE\n":"IMPOSSIBLE\n");
    return 0;
  }
  for(i=1;i<n;i++){
    scanf("%d",&a);
    G = gcd(G,a);
    MAX = max(MAX,a);
  }
  printf((k<=MAX && k%G==0) ? "POSSIBLE\n":"IMPOSSIBLE\n");
}