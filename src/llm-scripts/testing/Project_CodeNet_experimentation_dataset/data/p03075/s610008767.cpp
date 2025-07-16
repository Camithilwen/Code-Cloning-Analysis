#include<bits/stdc++.h>
using namespace std;
int main(void){
int x[5];
for(int i=0;i<5;i++)
    cin>>x[i];
int k;cin>>k;
sort(x,x+5);
cout<<((x[4]-x[0])>k?":(":"Yay!")<<endl;
return 0;}
