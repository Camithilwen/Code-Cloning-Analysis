#include <bits/stdc++.h>
using namespace std; 
int main() {
  int A;
  int B;
  cin>>A>>B;
  int i=0;
  int j=B-A;
  int sum=0;
  int C=A;
  while(i<=j){
    A=C;
    int a=A%10;//A=12345の時5
    A/=10;//A=1234
    int b=A%10;
    A/=10;//A=123
    A/=10;//A=12
    int d=A%10;
    A/=10;//A=1
    int e=A;
    if(a==e&&b==d){
      sum+=1;
    }
    C++;
    i++;
  }
  cout<<sum<<endl;

}
