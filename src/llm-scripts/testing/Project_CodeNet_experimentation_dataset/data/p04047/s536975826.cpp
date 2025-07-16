#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e5+500;
int w[N],n;
int main()
{
    scanf("%d",&n);int ans=0;
    for(int i=1;i<=2*n;i++)scanf("%d",w+i);
    sort(w+1,w+n*2+1);
    for(int i=1;i<=2*n;i+=2)ans+=w[i];
    cout<<ans<<endl;
}