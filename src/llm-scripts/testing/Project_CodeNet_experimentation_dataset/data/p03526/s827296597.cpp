#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
    ll x;
    ll y;
};
node a[5007];
int n;

bool cmp(node p,node q)
{
    if (p.x+p.y==q.x+q.y) return p.y<q.y;
    return p.x+p.y<q.x+q.y;
}
int main(){
    ios::sync_with_stdio(false);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    scanf("%lld%lld",&a[i].x,&a[i].y);

    priority_queue<int>q;
  //  n=n+1;
  //  a[n].x=1e9+10;
  //  a[n].y=1e9+10;
    sort(a+1,a+n+1,cmp);

    ll tmp=0;

    ll t=0;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
       // cout<<ans<<" "<<a[i].x<<a[]
        if (tmp<=a[i].x)
        {
            tmp+=a[i].y;
            q.push(a[i].y);
            ans++;
        }
        else
        {
            if (a[i].y<q.top())
            {
                tmp-=q.top();
                q.pop();
                tmp+=a[i].y;
                q.push(a[i].y);
            }
        }




    }
    printf("%d\n",ans);
}
