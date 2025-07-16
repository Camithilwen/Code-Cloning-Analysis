#include <bits/stdc++.h>
#define r(i,n) for(i=0;i<n;i++)
using namespace std;
int main(){
  int a,b,i;
  while(cin>>a>>b,a){
    int c[a],s=0,k=0,p=0;
    r(i,a){cin>>c[i];p+=c[i];}
    sort(c,c+a);
    for(i=a-1;i>=0;i--){
      k++;
      if(k==b){
        s+=c[i];
        k=0;
      }
    }
    cout<<p-s<<endl;;
  }
}