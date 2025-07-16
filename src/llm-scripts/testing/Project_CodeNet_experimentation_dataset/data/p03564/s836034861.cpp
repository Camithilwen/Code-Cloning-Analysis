#include <bits/stdc++.h>
using namespace std;

int val=1,n;
double k;
int main (){
    cin>>n>>k;
    int z=k;
    while(double(k)/2>1){
        val++;
        k/=2;
    }
   
  if(n>=val){
       cout<<pow(2,val)+z*(n-val); 
    }
    
    else{
        cout<<pow(2,n);
    }
}