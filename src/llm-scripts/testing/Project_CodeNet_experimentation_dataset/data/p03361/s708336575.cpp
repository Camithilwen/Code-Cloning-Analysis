#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

str a[60];

#define fi first
#define se second

#define DIRMAX 4
pair<int,int> dir[4]=
{
    { 0,-1},
    {-1, 0},
    { 1, 0},
    { 0, 1},
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h,w;cin>>h>>w;

    ss maketop;
    for(int i=0;i<w+2;i++)maketop<<".";

    a[0]=maketop.str();
    a[h+1]=maketop.str();

    for(int i=0;i<h;i++)
    {
        str s;
        cin>>s;
        ss makemid;

        makemid<<"."<<s<<".";
        
        a[i+1]=makemid.str();
    }

    bool ans=true;

    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)
    {
        if(a[i][j]=='#')
        {
            bool c=true;
            for(int k=0;k<DIRMAX;k++)
            if(a[i+dir[k].fi][j+dir[k].se]=='#')
            {
                c=false;
                break;
            }

            if(c)
            {
                ans=false;
                break;
            }
        }
    }

    puts(ans?"Yes":"No");

    return 0;
}
