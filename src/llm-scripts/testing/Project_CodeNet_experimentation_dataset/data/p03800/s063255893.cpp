///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=100005;
int n;
string s;
char ses[M];
char fnd(int pos,char cur,char dan)
{
    if(cur=='S')
    {
        if(s[pos]=='o')return dan;
        else
        {
            if(dan=='S')return 'W';
            else return 'S';
        }
    }
    else if(cur=='W')
    {
        if(s[pos]=='x')return dan;
        else
        {
            if(dan=='S')return 'W';
            else return 'S';
        }
    }
}
void chk(char x,char y)
{

    ses[0]=x;
    ses[1]=y;
    ses[n-1]=fnd(0,x,y);
    for(int i=2;i<=n;i++)
    {
        char yo=fnd(i-1,ses[i-1],ses[i-2]);
        if(i==n-1)
        {
            if(yo!=ses[n-1])
            {
                return ;
            }
        }
        else if(i==n)
        {
            if(yo!=ses[0])return ;
            continue;
        }
        ses[i]=yo;
    }
    ses[n]='\0';
    cout<<ses<<endl;
    exit(0);
}
 main()

{
    fast
    cin>>n;
    cin>>s;
    chk('S','W');
    chk('S','S');
    chk('W','S');
    chk('W','W');
    cout<<"-1"<<endl;
    return 0;

}



































