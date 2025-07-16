#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,a,i,k,x;
    cin >> n;
    k=0;x=n;
    for(i=0;i<n;i++)
    {
        cin >> a;
    if(a<=x)
    {
        k++;
        x=a;
    }
    }

    cout << k << endl;

}
