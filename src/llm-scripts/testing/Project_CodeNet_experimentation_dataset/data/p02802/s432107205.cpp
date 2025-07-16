#include <iostream>
#include <algorithm>
using namespace std;

#include <cmath>    //floor ceil
#include <cstdlib>  //abs
#include <cstdio>
#include <climits>  //INT_MAX
#include <cstring>
#define endl "\n"
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define lli long long int
#define MOD 1000000007
#include <map>
#define mp make_pair
#define mii map<int,int>
/*---------------------------------------------------CODE STARTS FROM HERE---------------------------------------------------*/

int main ()
{
    int n,m,ac=0,p=0;
    cin>>n>>m;
    int a[n],wa[n];
    for (int i=0;i<n;i++) a[i]=0,wa[i]=0;
    while(m--)
    {
        int x;
        string s;
        cin>>x>>s;
        if(a[x-1]==0 && s=="AC") { a[x-1]=1; ac++; p += wa[x-1];}
        else if(a[x-1]==0 && s=="WA") wa[x-1]++;
        //debug(wa[x-1]);
    }
    printf("%d",ac);
    printf(" ");
    printf("%d",p);
    return 0;
}
