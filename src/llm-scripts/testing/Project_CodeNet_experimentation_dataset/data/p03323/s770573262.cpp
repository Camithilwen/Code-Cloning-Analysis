///بِسْمِ الّٰلهِ الرَّحْمٰنِ الرَحِيْمِ
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1.0)
int main()
{
     ios_base::sync_with_stdio(false);cin.tie(NULL);
     ll int i,n,t,j=0,p,x,a=0,b,l=0,r=0,y,k,c,sum=0,m,d;
     cin>>a>>b;
     l=max(a,b);
     r=min(a,b);
     p=16-(a+b);
     x=p/2;
     if(p%2==1){
        x++;
     }
     //cout<<x<<" "<<l-r<<endl;
     if((l-r)<=x){
        cout<<"Yay!"<<endl;
     }
     else{
        cout<<":("<<endl;

     }

     return EXIT_SUCCESS;
}

