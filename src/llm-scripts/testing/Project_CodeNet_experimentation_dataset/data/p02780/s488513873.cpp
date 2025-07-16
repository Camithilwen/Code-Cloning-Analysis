#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n ,k;
    cin>>n>>k;
    cout.precision(15);

    double p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        p[i] = (p[i] + 1)/2;
    }
    double curr =0, ans =0 ;

    for(int i=0;i<k;i++)
    {
        curr += p[i];
    }
    ans =max( ans, curr);
    for(int i = k ;i< n ;i++)
    {
        curr = curr - p[i - k] + p[i];
        ans = max( ans , curr);
    }
    printf("%.12f" , ans);

}