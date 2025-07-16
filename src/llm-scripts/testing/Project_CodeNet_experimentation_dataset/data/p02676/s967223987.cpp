#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007


int main()
{
    int t=1;
    //cin>>t;


    while( t-- )
    {
        int k;
        cin>>k;

        string s;
        cin>>s;

        if( s.size()<=k )
            cout<<s;
        else
        {
            for( int i=0 ; i<k ; i++ )
                cout<<s[i];
            cout<<"..."<<endl;
        }
    }
    return 0;
}
