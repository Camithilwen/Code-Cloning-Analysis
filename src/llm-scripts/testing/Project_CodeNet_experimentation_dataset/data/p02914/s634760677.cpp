#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
 int n;
 cin>>n;
 priority_queue<int> que;
 int ala=0,a,k=0,t,s;
 for(int i=0;i<n;i++){
   cin>>a;
   que.push(a);
   ala^=a;
 }
 for(int i=59;i>=0;i--){
   if(que.empty())break;
    if(ala&(1LL<<i)){
     while(!que.empty()&&(que.top()&(1LL<<i))){
       que.push(que.top()^(1LL<<i));
       que.pop();
      // cerr<<que.top()<<' ';
     }
     continue;
   }
   if(!(que.top()&(1LL<<i)))continue;
    if(!(k&(1LL<<i)))k^=que.top();
    t=que.top();que.pop();
    while(!que.empty()&&(que.top()&(1LL<<i))){
      que.push((t^que.top()));
      que.pop();
    //  cerr<<que.top()<<' ';
    }
    

 }
 cerr<<ala<<' '<<k<<endl;
 cout<<(ala^k)+k;
return 0;
}
