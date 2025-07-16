 #include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,sum,sub,mul;
  cin>>a>>b;
  sum=a+b;
  sub=a-b;
  mul=a*b;
  
  int ans = max(sum,max(sub,mul));
  
  if(ans==0)
  cout<<0<<endl;
  else
  cout<<ans<<endl;
}