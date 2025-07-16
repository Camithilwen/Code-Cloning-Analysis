#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n=s.size();
  for(int i=0;i<(1<<(n-1));i++){
    int ans=s[0]-'0';
    vector<char> enzan;
    for(int j=0;j<n-1;j++){
      if(i&(1<<j)){
        ans-=s[j+1]-'0';
        enzan.push_back('-');
      }else{
        ans+=s[j+1]-'0';
        enzan.push_back('+');
      }
    }
    if(ans==7){
      cout<<s[0]<<enzan[0]<<s[1]<<enzan[1]<<s[2]<<enzan[2]<<s[3]<<'='<<7<<endl;
      return 0;
    }
  }      
  return 0;
}