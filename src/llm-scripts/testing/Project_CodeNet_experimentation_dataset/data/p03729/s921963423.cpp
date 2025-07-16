#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string a,b,c; cin>>a>>b>>c;
    int l=a.length(),r=b.length(),p=c.length();
    if(a[l-1]==b[0] && b[r-1]==c[0])cout<<"YES";
    else cout<<"NO";
}
