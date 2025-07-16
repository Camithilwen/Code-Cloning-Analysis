#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,l[52],i,j,sum=0;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>l[i];
    }
    sort(l,l+n);
    for(j=n-1;j>=n-k;j--){
        sum+=l[j];
    }
    cout<<sum;
    return 0;
}
