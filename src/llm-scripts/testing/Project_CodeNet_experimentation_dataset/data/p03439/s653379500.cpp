#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  string temp;
  string A[N];
  
  cout<<0<<endl;
  cin>>temp;
  if(temp=="Vacant"){
    cout<<0<<endl;
    return 0;
  }
  if(temp=="Male"){
    A[0]="Male";
  }
  if(temp=="Female"){
    A[0]="Female";
  }
  
  cout<<N-1<<endl;
  cin>>temp;
  if(temp=="Vacant"){
    cout<<N-1<<endl;
    return 0;
  }
  if(temp=="Male"){
    A[N-1]="Male";
  }
  if(temp=="Female"){
    A[N-1]="Female";
  }
  int l=N-1;
  int r=0;
  int k=22;
  while(k){
    k--;
    int m=(l+r)/2;
    cout<<m<<endl;
    cin>>temp;
    if(temp=="Vacant"){
      cout<<m<<endl;
      return 0;
    }
    if(temp=="Male"){
      A[m]="Male";
    }
    if(temp=="Female"){
      A[m]="Female";
    }  
    if((l-m)%2 == 0 && A[l] == A[m]){
      l=m;
      continue;
    }
    if((l-m)%2 == 0 && A[l] != A[m]){
      r=m;
      continue;
    }    
    if((l-m)%2 == 1 && A[l] == A[m]){
      r=m;
      continue;
    }    
    if((l-m)%2 == 1 && A[l] != A[m]){
      l=m;
      continue;
    } 

   }
  cout<<3<<endl;

  return 0;
}
