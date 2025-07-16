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
            string s;
            cin>>s;
            int l,r;
            string t;
            if(s.size()<2)
            {
                 cout<<"-1 -1";
                 return 0;
            }
            if(s.size()==2)
            {
                 if(s[0]==s[1])
                 {
                      cout<<"1 2";
                      return 0;
                 }
                 else
                 {
                      cout<<"-1 -1";
                      return 0;
                 }
            }
            for(int i=0;i<s.size()-2;++i)
            {
                 t = s.substr(i,3);
                 sort(t.begin(),t.end());
                 if(t[0]==t[1] || t[1]==t[2])
                 {
                      cout<<i+1<<" "<<i+3;
                      return 0;
                 }
                 //cout<<t<<"\n";
            }
            cout<<"-1 -1";
       }
}
