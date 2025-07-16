#include<bits/stdc++.h>
using namespace std;
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long i,j,k,l,m,n,o,p,q;
    while(cin>>m>>n>>o>>p)
    {
        if(m+n>o+p)
            cout<<"Left"<<endl;
        else if(m+n<o+p)
            cout<<"Right"<<endl;
        else
            cout<<"Balanced"<<endl;
    }
    return 0;
}