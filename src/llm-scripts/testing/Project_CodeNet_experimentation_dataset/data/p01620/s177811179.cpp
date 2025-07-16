#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
using namespace std; 
int main(){
  char x[52];
  for(int i='a';i<='z';i++){
    x[i-'a']=i;
  }
  for(int i='A';i<='Z';i++){
    x[26+i-'A']=i;
  }

int n;
  while(cin>>n,n!=0){
    int k[n];
    string s;
    for(int i=0;i<n;i++){
      cin>>k[i];
    }
    cin>>s;
    for(int i=0;i<s.size();i++){
      int b=distance(x,find(x,x+52,s[i])); 
      int c=(b-k[i%n]+52)%52;
      cout<<x[c];
    }
    cout<<endl;
  }
  return 0;
}