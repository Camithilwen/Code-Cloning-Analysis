#include<bits/stdc++.h>
using namespace std;

int main(){
  int m,n_min,n_max,gap,temp=0;
  while(1){
    cin >> m >> n_min >> n_max;
    if(m==0 && n_min==0 && n_max==0){break;}
    int P[m+1];
    P[0]=-1;
    for(int i=1;i<=m;i++){
      cin >> P[i];
    }
    gap=0;
    for(int i=n_min;i<=n_max;i++){
      if(P[i]-P[i+1]>=gap){
        gap=P[i]-P[i+1];
        temp=i;
      }
    }
    cout << temp << endl;
  }
}