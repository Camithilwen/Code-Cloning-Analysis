#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,x=0;string A,B,C;
  cin>>N>>A>>B>>C;
  for(int i=0;i<N;i++){
    char a=A.at(i),b=B.at(i),c=C.at(i);
    if(a==b){if(a!=c)x++;}
    else{
      if(a==c||b==c)x++;
      else x+=2;
    }
  }
  cout<<x<<endl;
}