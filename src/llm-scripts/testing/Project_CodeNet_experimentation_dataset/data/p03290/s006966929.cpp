#include <bits/stdc++.h>
using namespace std;
int main(){
  int D,G;
  cin>>D>>G;
  vector<pair<int,int>> vec(D);
  for(int i=0;i<D;i++){
    cin>>vec.at(i).first>>vec.at(i).second;
  }
  int ans=0;
  for(int i=0;i<(1<<D);i++){
    bitset<10> bit(i);
    int point=0,ans_=0;
    for(int j=0;j<D;j++){
      if(bit.test(j)){
        point+=100*(j+1)*vec.at(j).first+vec.at(j).second;
        ans_+=vec.at(j).first;  
      } 
    }
    int de=D;
    while(point<G&&de>=1){
      if(de*100<=G-point&&!bit.test(de-1)){
        ans_+=min((G-point)/(de*100),vec.at(de-1).first-1);
        point+=(min((G-point)/(de*100),vec.at(de-1).first-1))*(de*100); 
      }
      de--;
    }
    if(point>=G&&ans==0){
      ans=ans_;
    }
    if(point>=G&&ans_<ans) {
      ans=ans_;
    }
  }
  cout<<ans<<endl;
}