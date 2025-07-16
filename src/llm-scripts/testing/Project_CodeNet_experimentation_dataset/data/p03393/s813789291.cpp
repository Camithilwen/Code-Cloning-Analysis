#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int N=S.size();
  if(S=="zyxwvutsrqponmlkjihgfedcba"){
    cout<<"-1"<<endl;
  }
  else if(N==26){
    vector<char> v(26);
    for(int i=0;i<26;i++){
      v[i]=S[i];
    }
    next_permutation(begin(v),end(v));
    for(int i=0;i<26;i++){
      cout<<v[i];
      if(v[i]!=S[i]){
        cout<<endl;
        break;
      }
    }
  }
  else{
    for(int j=0;j<26;j++){
      char a='a'+j;
      int X=0;
      for(int i=0;i<N;i++){
        if(S[i]==a){
          X++;
          break;
        }
      }
      if(X==0){
        cout<<S<<a<<endl;
        break;
      }
    }
  }
      
}