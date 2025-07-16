
#include<bits/stdc++.h>
using namespace std;
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long i,j,k,l,m,n,o,p,q;
    while(cin>>m>>n)

    {
        i=m+n;
        j=m-n;
        k=m*n;
        cout<<max(i,max(j,k))<<endl;

    }
    return 0;
}