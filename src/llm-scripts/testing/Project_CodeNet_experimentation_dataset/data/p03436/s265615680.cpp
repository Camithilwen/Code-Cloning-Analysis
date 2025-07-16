#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W; cin>>H>>W;
  queue<int>A;
  queue<int>B;
  int ans=0;
  vector<vector<char>>C(H+2,vector<char>(W+2,'#'));
  for(int i=1;i<=H;i++){
    string S;cin>>S;
    for(int j=1;j<=W;j++){C[i][j]=S.at(j-1);if(C[i][j]=='#'){ans++;}}
  }
  A.push(1);
  B.push(1);
  vector<vector<bool>>Z(H,vector<bool>(W,false));
  Z[0][0]=true;
  int count=1;
  for(int i=2;;i++){
    int z=count;
    count=0;
    for(int j=0;j<z;j++){
      if(C[A.front()+1][B.front()]=='.'&&!Z[A.front()][B.front()-1]){count++;Z[A.front()][B.front()-1]=true;A.push(A.front()+1);B.push(B.front());if(A.front()+1==H&&B.front()==W){cout<<H*W-ans-i<<endl;return 0;}}
      if(C[A.front()-1][B.front()]=='.'&&!Z[A.front()-2][B.front()-1]){count++;Z[A.front()-2][B.front()-1]=true;A.push(A.front()-1);B.push(B.front());if(A.front()-1==H&&B.front()==W){cout<<H*W-ans-i<<endl;return 0;}}
      if(C[A.front()][B.front()+1]=='.'&&!Z[A.front()-1][B.front()]){count++;Z[A.front()-1][B.front()]=true;A.push(A.front());B.push(B.front()+1);if(A.front()==H&&B.front()+1==W){cout<<H*W-ans-i<<endl;return 0;}}
      if(C[A.front()][B.front()-1]=='.'&&!Z[A.front()-1][B.front()-2]){count++;Z[A.front()-1][B.front()-2]=true;A.push(A.front());B.push(B.front()-1);if(A.front()==H&&B.front()-1==W){cout<<H*W-ans-i<<endl;return 0;}}
      A.pop();B.pop();
    }
    if(count==0){cout<<-1<<endl; return 0;}
  }
}