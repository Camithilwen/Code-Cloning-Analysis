#include <bits/stdc++.h>
#define ll long long 
using namespace std;

#define pb push_back

void solve(){
 ll sx,sy,tx,ty; 
 cin>>sx>>sy>>tx>>ty;

 ll dx=tx-sx;
 ll dy=ty-sy;
 string s1,s2;
 for(int i=0;i<dy;i++){
    s1+='U';
    s2+='D';
 } 
 for(int i=0;i<dx;i++)
{
  s1+='R';
  s2+='L';
}
string f1= "LU"+s1+"RD";
string f2="RD"+s2+"LU";
cout<<s1+s2+f1+f2<<endl;
}


int main() {
   #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

 ios_base::sync_with_stdio(0);
 cin.tie(0);

int t=1 ;  while(t--)
 solve();

return 0;
}
