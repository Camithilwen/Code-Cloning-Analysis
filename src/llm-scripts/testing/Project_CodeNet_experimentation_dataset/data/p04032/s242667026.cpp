#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int l=s.length(),j,k;
  vector<int> v(26,-1);
  for(j=0;j<l;j++){
    k=s[j]-'a';
    if(v[k]==-1||j-v[k]>2) v[k]=j;
    else{
      cout<<v[k]+1<<' '<<j+1<<endl;
      return 0;
    }
  }
  cout<<"-1 -1"<<endl;
}