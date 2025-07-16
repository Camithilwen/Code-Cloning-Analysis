#include <bits/stdc++.h>
using namespace std;
int main(){
long long N,A,B,counter=0;
cin>>N>>A>>B;
long long a[100000];
for(int j=0; j<N;j++){
cin>>a[j];}
for(int j=0; j<N-1;j++){
if((a[j+1]-a[j])*A<=B){
counter+=A*(a[j+1]-a[j]);}
else
counter+=B;
}
cout<<counter<<endl;}
