#include<bits/stdc++.h>

using namespace std;
int main(){
  while(1){
  int n;
  cin>>n;
    int m;
    cin>>m;
    if(n==0&&m==0){break;}
  vector<vector<int>> v(n+1);//??¨?????????
  vector<int> s(n+1,0);//??????
s[1]=1;
  for(int i=0;i<m;i++){
    int a;
    cin>>a;
    int b;
    cin>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  vector<vector<int>> r(n+1);//?????°???????????¨
  r[0].push_back(1);
  int num=0;
  while(1){
  int change=0;
  if(r[num].empty()==false){
    for(unsigned int j=0;j<r[num].size();j++){
      for(unsigned int i=0;i<v[r[num][j]].size();i++){
        if(s[v[r[num][j]][i]]==0){
          s[v[r[num][j]][i]]=1;
          r[num+1].push_back(v[r[num][j]][i]);
          change=1;
        }
      }
    }
  }
    if(change==0){break;}
    if(num==1){break;}
    num++;
  }
  int kazu=0;
  for(unsigned int i=0;i<s.size();i++){
    if(s[i]==1){kazu++;}
  }
  cout<<kazu-1<<endl;

}
}