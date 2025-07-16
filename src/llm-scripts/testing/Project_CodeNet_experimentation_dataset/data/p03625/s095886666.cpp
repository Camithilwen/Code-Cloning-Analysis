#include<bits/stdc++.h>
using namespace std;

main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    long long i,j,k,l,m,n,o,p;
 string s;
 while(cin>>n){
    int x[n];
    map<long long,long long>mp;

    for(i=0;i<n;i++){
        cin>>x[i];

    }
    sort(x,x+n);
   long long a=0,b=0;
   for(i=n-1;i>0;i--){
    if(x[i]==x[i-1]){
        if(a==0)a=x[i];
        else if(b==0)b=x[i];
        else break;
        i--;
    }
   }
   cout<<a*b<<endl;
 }
    return 0;

}
