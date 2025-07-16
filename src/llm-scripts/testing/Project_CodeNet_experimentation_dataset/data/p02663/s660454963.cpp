#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    
    int x  =  (c-a);
    int y  =  (d-b);
    int ans  =  (x*60)+y;
    ans=ans-k;
    
    cout<<ans<<endl;
    
}