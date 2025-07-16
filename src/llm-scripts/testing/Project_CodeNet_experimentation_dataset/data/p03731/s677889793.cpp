#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int n,t;
  cin>>n>>t;
  
  vector<int>time(n);
  
  for(int i=0;i<n;i++){
   cin>>time[i]; 
  }
  
  int dif;
  long long sum=t;
  for(int i=1;i<n;i++){
    dif=time[i]-time[i-1];
    
    if(dif<=t)sum+=dif;
    else sum+=t;
  }

  cout<<sum<<endl;
  return 0;
}