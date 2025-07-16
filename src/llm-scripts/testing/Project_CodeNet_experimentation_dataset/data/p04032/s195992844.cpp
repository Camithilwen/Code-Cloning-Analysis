#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
using namespace std;

typedef long long ll;
typedef short int sh;

const int inf=0x3f3f3f3f;
const int MAX=1e5+10;
const int mod=1e9+7;

vector<int>vec[26];
char str[MAX];

void Get_Pos()
{
    for(int i=0;str[i];i++)
    {
        int k=str[i]-'a';
        vec[k].push_back(i);
    }
}

void Solve()
{
    for(int i=0;i<26;i++)
    {
        int l=vec[i].size();
        for(int j=0;j<l;j++)
        {
            int t=vec[i].at(j);
            for(int k=j+1;k<l;k++)
            {
                int r=vec[i].at(k);
                if(((k-j+1)<<1)>r-t+1)
                {
                    printf("%d %d\n",t+1,r+1);
                    return;
                }
            }
        }
    }
    printf("-1 -1\n");
}

int main()
{
    int n;
    while(scanf("%s",str)!=EOF)
    {
        Get_Pos();
        Solve();
    }
    return 0;
}