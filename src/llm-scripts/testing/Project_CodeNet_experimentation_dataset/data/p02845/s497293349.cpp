#include <bits/stdc++.h>
using namespace std;
static const long long MOD=1000000007;

int main(){
  int N,temp;
  cin >> N;
  int c1,c2,c3;
  c1=0;
  c2=0;
  c3=0;
  long long ans=1;
  for(int i=0;i<N;i++){
    int cnt=0;
    int flag=-1;
    cin>>temp;
    if(c1==temp){
      cnt++;
      flag=1;
    }
    if(c2==temp){
      cnt++;
      flag=2;
    }
    if(c3==temp){
      cnt++;
      flag=3;
    }
    ans=ans*cnt%MOD;
    if(flag==1){
      c1++;
    }
    if(flag==2){
      c2++;
    }    
    if(flag==3){
      c3++;
    }  
  }
  cout<<ans<<endl;    
  return 0;
}



    