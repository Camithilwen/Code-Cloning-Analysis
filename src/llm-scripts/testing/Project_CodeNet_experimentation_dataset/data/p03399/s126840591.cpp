#include<bits/stdc++.h>
using namespace std;
int main(){
int A,B,C,D,a;
  cin>>A>>B>>C>>D;
  a=min(min(min(A+C,A+D),B+C),B+D);
cout<<a<<endl;
}