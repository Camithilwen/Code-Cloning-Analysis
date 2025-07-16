#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);

       int t=1;
       //cin>>t;
       while(t--)
       {
               string a,b,c;
               cin>>a>>b>>c;
               char ch = a[0];
               int i=0;
               a.erase(i,1);
               char ans;
               while(true)
               {
                    if(ch=='a')
                    {
                         if(a.size()==0)
                         {
                              ans = 'A';
                              break;
                         }
                         ch = a[0];
                         a.erase(i,1);
                    }
                    else if(ch=='b')
                    {
                         if(b.size()==0)
                         {
                              ans = 'B';
                              break;
                         }
                         ch = b[0];
                         b.erase(i,1);
                    }
                    else
                    {
                         if(c.size()==0)
                         {
                              ans = 'C';
                              break;
                         }
                         ch = c[0];
                         c.erase(i,1);
                    }
               }
               cout<<ans;
       }
}
