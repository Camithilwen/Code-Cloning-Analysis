#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W; cin>>H>>W;
  vector<vector<char>>A(H+2,vector<char>(W+2,'.'));
  for(int i=1;i<=H;i++){
    string S; cin>>S;
    for(int j=1;j<=W;j++){
      A[i][j]=S.at(j-1);
    }
  }
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      if(A[i][j]=='.')continue;
      if(A[i+1][j]=='#')continue;
      if(A[i-1][j]=='#')continue;
      if(A[i][j+1]=='#')continue;
      if(A[i][j-1]=='#')continue;
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}