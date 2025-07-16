#include<bits/stdc++.h>
using namespace std;
#define int long long int 

int32_t main()
{
    int d,g;
    cin>>d>>g;

    vector<array<int,2>> s(d);
    for(int i=0;i<d;i++)
    cin>>s[i][0]>>s[i][1];
     int ans=INT_MAX;
    for(int i=0;i<(1<<d);i++)
    {
        int left=-1,sum=0,count=0;
        for(int j=0;j<d;j++)
        {
            if((i>>j)&1)
                sum+=100*(j+1)*s[j][0]+s[j][1],count+=s[j][0];
            else
            left=j;
        }
        if(sum<g)
        {
            int c=100*(left+1);
            int need=(g-sum+c-1)/c;
            if(need>=s[left][0])
            continue;
            count+=need;
        }
        ans=min(ans,count);
    }
    cout<<ans<<endl;



}