#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  sort(a.begin(),a.end());
  int flag=0;
  for(int i=0;i<n-1;i++){
    if(a.at(i)==a.at(i+1)){
      flag=1;
    }
  }
  if(flag==0){
    cout<<"YES";
  }else{
    cout<<"NO";
  }
}