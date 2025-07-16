#include<bits/stdc++.h>
using namespace std;

int main(){
  int k;
  string s;
 
  cin >> k >> s;
  
  int cnt=0;
  for(int i=0;i<s.length();i++){
    cnt++;
  }

  if(cnt<=k){
   cout<<s<<endl;
  }
  else{
    for(int i=0;i<k;i++){
      cout<<s[i];
  }
     cout<<"..."<<endl;
  }
  
return 0;
}

