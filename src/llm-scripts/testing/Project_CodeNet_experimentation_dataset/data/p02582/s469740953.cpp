#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
  char s[3];
  cin>>s[0]>>s[1]>>s[2];
  int max=0, locmax=0;
  for(int i=0;i<3;i++){
    if(s[i] == 'R'){
      locmax++;
    }
    else{
      locmax=0;
    }
    if(locmax>max){
      max=locmax;
    }
  }
  cout<<max;
}
      
