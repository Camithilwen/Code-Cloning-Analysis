#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5 + 5;
int num[maxn], x[maxn];

int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d%d",x+i,num+i);
    }
    int l=1,r=n;
    long long ans=0;
    long long sum=0;
    int nows;
    bool flag;
    if(num[1]>=num[n]){
        nows=x[n];sum+=num[r];
        flag=1;
    }
    else{
        nows=x[1];sum+=num[l];
        flag=0;
    }
    while(s<x[r]&&s>x[l]){
        //printf("%d %d %lld %lld\n",l,r,ans,sum);
        if(flag){
            if(num[l]>=sum){
                ans+=abs(nows-x[l]);
                flag=0;
                nows=x[l];
                sum+=num[l];
                r--;
            }
            else
                sum+=num[l++];
        }
        else{
            if(num[r]>sum){
                ans+=abs(x[r]-nows);
                flag=1;
                nows=x[r];
                sum+=num[r];
                l++;
            }
            else
                sum+=num[r--];
        }
    }
    //printf("%d %d %lld %lld\n",l,r,ans,sum);
    if(s>x[r]){
        ans+=abs(nows-x[l]) + abs(nows-s);
    }
    else ans+=abs(nows-s) + abs(nows-x[r]);
    printf("%lld\n",ans);
    return 0;
}
