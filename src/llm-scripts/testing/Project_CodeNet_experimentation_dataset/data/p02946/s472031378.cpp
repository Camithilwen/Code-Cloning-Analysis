#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,i,n;
    cin>>a>>b;
    
    n=((a*2)-1)/2;
    for(i=0;i<n;i++)
    {
        a--;
        cout<<b-a<<" ";
    }
    cout<<b<<" ";
    a=0;
    for(i=n+1;i<2*n+1;i++)
    {
        a++;
        cout<<b+a<<" ";
    }
    return 0;
}
