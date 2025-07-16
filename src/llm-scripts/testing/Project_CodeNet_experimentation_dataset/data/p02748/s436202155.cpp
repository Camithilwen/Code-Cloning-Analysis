#include <bits/stdc++.h>
using namespace std;
int main(){
  long long A,B,M;
  cin>>A>>B>>M;
  vector<int> a(A);
  for(int i=0;i<A;i++)
    cin>>a.at(i);
  vector<int> b(B);
  for(int i=0;i<B;i++)
    cin>>b.at(i);
  vector<vector<int>> c(M,vector<int>(3));
  for(int i=0;i<M;i++){
    for(int j=0;j<3;j++)
      cin>>c.at(i).at(j);
  }
  long long min=a.at(0)+b.at(0);
  for(int i=0;i<M;i++){
    if(a.at(c.at(i).at(0)-1)+b.at(c.at(i).at(1)-1)-c.at(i).at(2)<min)
      min=a.at(c.at(i).at(0)-1)+b.at(c.at(i).at(1)-1)-c.at(i).at(2);
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  if(a.at(0)+b.at(0)<min)
    min=a.at(0)+b.at(0);
  cout<<min<<endl;

}
