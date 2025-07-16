     #include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  for(int i=0;i<8;i++){
    string ans;
    ans+=S.at(0);
    int sum=S.at(0)-'0';
    for(int j=0;j<3;j++){
      if(i>>j&1){
        sum+=S.at(j+1)-'0';
        ans+="+";
        ans+=S.at(j+1);
      }
      else{
        sum-=S.at(j+1)-'0';
        ans+="-";
        ans+=S.at(j+1);
      }
    }
    if(sum==7){
        cout<<ans<<"=7"<< endl;
        return 0;
      
    }
  }
} 