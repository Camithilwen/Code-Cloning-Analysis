#include<bits/stdc++.h>
using namespace std;
int st[1000003][5];
string q;
int dmc(int g,int k)
{
    if(g==q.length())return k;
    if(st[g][k]!=1e9)return st[g][k];
    int z=1e8;
    if(!k)z=min((dmc(g+1,0)+(q[g]-'0')),(dmc(g+1,1)+10-(q[g]-'0')));
    else{
        z=min(z,dmc(g+1,0)+1+(q[g]-'0'));
        z=min(z,dmc(g+1,1)+10-((q[g]-'0')+1));
    }
    return st[g][k]=z;
}
int main()
{
    int g;
    cin>>q;
    reverse(q.begin(),q.end());
    for(g=0;q[g];g++)st[g][0]=st[g][1]=1e9;
    printf("%d\n",dmc(0,0));
    return 0;
}
