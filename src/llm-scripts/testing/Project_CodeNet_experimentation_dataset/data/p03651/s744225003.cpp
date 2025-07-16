#include<bits/stdc++.h>
using namespace std;
int main(){
long long g=0,n,a,mx=0,k;
cin>>n>>k;
for(int i=0;i<n;i++){
    cin>>a;
    mx=max(mx,a);
    g=__gcd(g,a);
}
if(k>mx){
    cout<<"IMPOSSIBLE";
}
else{
 if(k%g==0){
 cout<<"POSSIBLE";
}
else{
    cout<<"IMPOSSIBLE";
}
}
}