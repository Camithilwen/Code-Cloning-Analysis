/*
R         R R R R        R        R R R      R      R    R    R      R    R R R R                                                     
R         R             R R       R    RR    R R    R    R    R R    R    R              
R         R            R   R      R R R      R  R   R    R    R  R   R    R   R R                 
R         R R R       R R R R     R R        R   R  R    R    R   R  R    R     R                       
R         R          R       R    R   RR     R    R R    R    R    R R    R     R           
R R R R   R R R R   R         R   R     RR   R      R    R    R      R    R R R R               

*/


#include<bits/stdc++.h>
using namespace std;
#define  bf            ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  ll            long long
#define  pb            push_back
#define  pr            10
#define  mx            100000 // 10^6
#define  md            1000000007
#define  result(a)     cout<<a<<endl;
#define  forr(a,x)     for(int i=a;i<=x;i++)
#define  input(n,a)    int a[n];for(int i=0;i<n;i++)cin>>a[i];
#define  print(a)      for(auto it:a)cout<<it<<' '; //0-based 
#define  printt(n,a)   for(i=0;i<n;i++)cout<<a[i]<<' '; //1-based 
#define  sz(a)         cout<<a.size()<<endl; 
#define  prefx(n,a)    for(i=1;i<n;i++)a[i]=a[i-1]+a[i]; //0-based
#define  sortt(v)      sort(v.begin(),v.end());
#define  srt(n,a)      sort(a,a+n);
#define  rev(n,a)      reverse(a,a+n);
#define  revr(a)       reverse(a.begin(),a.end());
#define  yes           cout<<"Yes\n";
#define  no            cout<<"No\n";

int main()
{
  int a,b;
  cin>>a>>b;
  if(a<=8&&b<=8)
  {
    cout<<"Yay!\n";
  }
  else
  {
    cout<<":(\n";
  }
}
