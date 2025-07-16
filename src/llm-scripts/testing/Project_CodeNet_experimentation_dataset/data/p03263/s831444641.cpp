#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int H,W;
  cin>>H>>W;
  vector<vector<int>> A(H,vector<int>(W));
  for(vector<int> &v:A)
    for(int &i:v)
      cin>>i;
  int k=0;
  vector<vector<int>> B(0);
  for(int i=0;i<H;i++){
    for(int j=0;j<W-1;j++){
      if(A[i][j]%2==1){
        k++;
        A[i][j+1]+=A[i][j];
        B.push_back({i+1,j+1,i+1,j+2});
      }
    }
    if(A[i][W-1]%2==1 && i!=H-1){
      k++;
      A[i+1][W-1]+=A[i][W-1];
      B.push_back({i+1,W,i+2,W});
    }
  }
  cout<<k<<endl;
  for(vector<int> v:B)
    cout<<v[0]<<' '<<v[1]<<' '<<v[2]<<' '<<v[3]<<endl;
}