#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    if(c>min(a,b) && c<max(a,b))
    {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
   return 0;

}
