#include<bits/stdc++.h>

using namespace std;
string t;
string ans;

void dfs(int i,string s,int n);
void solve();

int main(void){
    cin >> t;
    solve();
    return 0;
}

void dfs(int i, string s, int n){
      if(i==3){
            if(n==7){
                  ans=s+"=7";
            }
            return ;
      }
      dfs(i+1,s + "+" + t[i + 1],n + (t[i + 1] - '0'));
      dfs(i+1,s + "-" + t[i + 1],n - (t[i + 1] - '0'));
 
}

void solve(){
    dfs(0,t.substr(0,1),t[0]-'0');
    cout << ans << endl;
}
