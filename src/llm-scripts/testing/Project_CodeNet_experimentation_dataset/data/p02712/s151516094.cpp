#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,s=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        if(i%3==0||i%5==0)
            continue;
        s+=i;
    }
    cout<<s<<endl;
}
