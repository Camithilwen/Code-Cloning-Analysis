#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

bool Cmp(pii a,pii b){
  if(a.first>b.first){
    return true;
  }else{
    return false;
  }
}

int main(){
  int n;
  cin>>n;
  vector<pii>team;
  for(int j=0;j<n;j++) team.push_back(pii(0,j));
  for(int i=0;i<(n*(n-1))/2;i++){
    int ta,tb,sa,sb;
    cin>>ta>>tb>>sa>>sb;
    if(sa>sb){
      team[--ta].first+=3;
    }else if(sa<sb){
      team[--tb].first+=3;
    }else{
      team[--ta].first++;
      team[--tb].first++;
    }
  }
  sort(team.begin(),team.end(),Cmp);
  //for(pii a : team)cout <<"score :" << a.first << " team num: " <<a.second << endl;
  //cout << endl;
  int ans[n];
  for(int i=0;i<team.size();i++){
    int cnt=0;
      while(team[i].first==team[i-1-cnt].first)cnt++;
    ans[team[i].second]=i+1-cnt;
  }
  for(int i=0;i<n;i++){
    cout << ans[i] << endl; 
  }
 return 0;
}