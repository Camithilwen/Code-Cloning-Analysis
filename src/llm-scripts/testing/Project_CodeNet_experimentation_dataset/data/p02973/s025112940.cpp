#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cstring>
using namespace std;
typedef long long ll;
int a[100100];
int c[100100];
bool check(int x,int i)
{
    if(c[x]<a[i])
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int bs(int l, int r,int i)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid,i)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int cnt=1;
    c[1] = a[1];
    for(int i=2;i<=n;i++)
    {
        int pos = bs(1,cnt,i);
        if(c[pos]<a[i])
        {
            c[pos] = a[i];
        }
        else
        {
            cnt++;
            c[cnt] = a[i];
        }
        
    }
    cout << cnt << endl;
    return 0;
}