#include <bits/stdc++.h>
using namespace std;
int main(){
 int N,X,T;
 cin>>N>>X>>T;
 
 if(N % X ==0){
  cout<<(N/X)*T<<endl;
 }
 else if(N % X !=0){
  cout<<((N/X)+1)*T<<endl;
 }
}