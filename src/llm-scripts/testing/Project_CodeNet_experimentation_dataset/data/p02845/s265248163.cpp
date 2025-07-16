#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,a,c=1,A[100002]={};A[0]=3;
  cin>>N;
  for(int i=0;i<N;i++){
    scanf("%d",&a);
    c*=(A[a]-A[a+1]++);
    c%=1000000007;
  }
  cout<<c<<endl; 
}