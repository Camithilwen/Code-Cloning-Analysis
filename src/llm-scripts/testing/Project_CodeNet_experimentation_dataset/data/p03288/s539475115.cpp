#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,j,n) for(int i=j;i<=n;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r;
    cin>>r;
    if(r<1200)
      cout<<"ABC";
    else if(r<2800 && r>=1200)
     cout<<"ARC";
    else 
    cout<<"AGC";
} 
