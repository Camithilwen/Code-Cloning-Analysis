#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  cout<<98<<" "<<99<<endl;
  a--;
  b--;
  for(int i=0;i<=48;i++){
    for(int j=0;j<=98;j++){
      if(i%2==0||j%2==0||a==0)
        cout<<'#';
      else{
        cout<<'.';
        a--;
      }
    }
    cout<<endl;
  }
  for(int i=0;i<=48;i++){
    for(int j=0;j<=98;j++){
      if(i%2==0||j%2==0||b==0)
        cout<<'.';
      else{
        cout<<'#';
        b--;
      }
    }
    cout<<endl;
  }
}