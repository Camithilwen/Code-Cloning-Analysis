#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
 int a;
 cin>>a;
 int ans =0;
 for(int i=0;i<3;i++){
   ans+=pow(a,i+1);
 }
 cout<<ans<<endl;
}