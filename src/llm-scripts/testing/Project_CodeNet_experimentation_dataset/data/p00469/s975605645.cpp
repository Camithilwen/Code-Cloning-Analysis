#include<bits/stdc++.h>
using namespace std;
set<unsigned int> s;
int n,m;
int cards[100];
bool used[100];
void solve(int cnt,string a){
  string tmp=a;
  if(cnt==m){
    s.insert(atoi(a.c_str()));
    return;
  }
  for(int i=0;i<n;i++){
    if(used[i]==true)continue;
    used[i]=true;
    stringstream ss;
    ss << cards[i];
    a+=ss.str();
    solve(cnt+1,a);
    a=tmp;
    used[i]=false;
  }
}

int main(){
  while(cin>>n,n){
    s.clear();
    cin>>m;
    for(int i=0;i<n;i++){
      used[i]=false;
      cin>>cards[i];
    }
    solve(0,"");
    // for(auto i:s)
    // cout << i << endl;

    cout << s.size() << endl;
  }
  return 0;
}