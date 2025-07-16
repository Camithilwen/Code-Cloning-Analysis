#include<bits/stdc++.h>
using namespace std;
int main()
{
string s;cin>>s;
  int n=s.size();
  if(n%2!=0)cout<<"No";
  else
  {int f=0;
    for(int i=0;i<n;i+=2)
  {
   if(s[i]=='h' && s[i+1]=='i')continue;
    else{f++;break;}
  }
   if(f==0)cout<<"Yes";
   else cout<<"No";
  }
  return 0;
}
