#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B;
  cin>>A>>B;
  int sum=0;
  for(int i=A;i<=B;i++){
    if((i%10==i/10000)&&((i%100)/10==(i/1000)%10)){
      sum+=1;
    }
  }
  cout<<sum<<endl;
}