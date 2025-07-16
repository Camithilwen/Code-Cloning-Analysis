#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#pragma GCC optimize(2)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const double eps=1e-5;
const double pi=acos(-1.0);
const int MOD=1e9+7;
const int maxn=1e5+10;
int a[maxn];
int main ()
{
    int n;
    scanf("%d",&n);
    a[0]=1e9;
    int len=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x<=a[len]){
            a[++len]=x;
        }
        else{
            int l=1,r=len,mid=(l+r)>>1;
            while(l<=r)
            {
                mid=(l+r)>>1;
                if(a[mid]<x){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            //cout<<mid<<endl;
            while(a[mid]>=x)
                mid++;
            a[mid]=x;
        }
    }
    printf("%d\n",len);
    return 0;
}