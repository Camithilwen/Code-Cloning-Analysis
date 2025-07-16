#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,L;
  cin>>N>>L;
  int A;
  A=L;
  int R=A+N-1;
  int eat;
  if(R<=0){
    eat=R;
  }
  else if(L>=0){
    eat=L;
  }
  else{
    eat=0;
  }
  int ans=(R+L)*(R-L+1)/2-eat;
  cout<<ans<<endl;
}
