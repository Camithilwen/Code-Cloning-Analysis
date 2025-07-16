#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[1020], b[1020];
int vote[1020];

int main()
{
    while(cin >> n>> m)
    {
        memset(vote, 0, sizeof vote);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);

        for(int i=1;i<=m;i++)
        {
            int j = 1;
            while(a[j] > b[i]) j++;
            vote[j]++;
        }
        printf("%d\n",max_element(vote+1,vote+n+1)-vote);
    }
    return 0;
}