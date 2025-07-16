#include <bits/stdc++.h>
using namespace std;






int main(){
  


  int n;
  cin>>n;
  
  vector<int> data(n+2);
  
  data.at(0)=0;
  data.at(n+1)=0;
  
  for (int i=1;i<=n;i++){
    int tmp;
    cin>>tmp;
    data.at(i)=tmp;
  }
  
  long long sum=0;
  
  for (int i=0;i<n+1;i++){
    sum+=abs(data.at(i+1)-data.at(i));
  }
  
  for (int i=1;i<=n;i++){
    cout<<sum-abs(data.at(i)-data.at(i-1))-abs(data.at(i+1)-data.at(i))+abs(data.at(i+1)-data.at(i-1))<<endl;
  }
  
    
      
    
    
  


    
  
  
  
}