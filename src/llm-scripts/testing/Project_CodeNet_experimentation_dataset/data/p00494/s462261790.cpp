#include<cstdio>
#include<vector>
#include<map>
#include<climits>
#include<algorithm>
#include<iostream>
using namespace std;
typedef pair<int,int> Pt;
#define MAX 1000001
#define fr first
#define sc second
int main(){
  string s;
  int ans = 0;
  cin >> s;
  for(int i=0;i<s.size();){
    int a = 0,b = 0,c = 0;
    for(;s[i]=='J';a++) i++;
    for(;s[i]=='O';b++) i++;
    for(;s[i]=='I';c++) i++;
    if(a>=b && b<=c) ans = max(ans,b);
  }
  cout << ans << endl;
}