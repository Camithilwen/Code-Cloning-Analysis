#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   string S;
   cin>>S;
   int len=S.size();
   int num;
   int ans=1000;
   rep(i,len-2){
       num=(S[i]-'0')*100+(S[i+1]-'0')*10+S[i+2]-'0';
       ans=min(ans,abs(753-num));
   }
   cout<<ans<<endl;
   
   
}