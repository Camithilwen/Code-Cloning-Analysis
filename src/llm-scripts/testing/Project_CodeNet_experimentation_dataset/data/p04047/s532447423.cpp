#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,res=0;
    scanf("%d",&n);
    n*=2;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i+=2)
    {
        res+=arr[i];
    }
    printf("%d",res);
}
