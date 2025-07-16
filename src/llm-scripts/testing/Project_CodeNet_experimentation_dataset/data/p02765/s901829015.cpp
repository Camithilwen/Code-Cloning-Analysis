#include <bits/stdc++.h>
using namespace std;
int n,r,ans;
int main()
{
    scanf("%d%d",&n,&r);
    if(n<10){
        ans=r+100*(10-n);
        printf("%d",ans);
    }else{
        ans=r;
        printf("%d",ans);
    }
    return 0;
}
