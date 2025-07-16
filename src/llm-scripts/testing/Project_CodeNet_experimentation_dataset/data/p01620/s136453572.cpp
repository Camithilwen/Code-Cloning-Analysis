#include<iostream>
#include<vector>
#include<string>

using namespace std; 

int main(){
  int n;
  vector<int> K(100);
  string s;
  string c="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

  while(1){
    int l=0;
    cin>>n;
    if(n==0)break;
    for(int i=0;i<n;i++) cin>>K[i];
    for(int j=n;j<100;j++){
      int count=0;
      if(count==n)l=count=0;
      K[j]=K[l];
      l++;
      count++;
    }
    cin>>s;
    for(int i=0;i<s.size();i++){
      for(int j=0;j<c.size();j++){
	if(s[i]==c[j]){
	  if(j-K[i]<0){
	    s[i]=c[c.size()+j-K[i]];
	    break;
	  }else{
	    s[i]=c[j-K[i]];
	    break;
	  }
	}
      }
    }
    cout<<s<<endl;
    s.clear();
    K.clear();
  }
  
  return 0;
}