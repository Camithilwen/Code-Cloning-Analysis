#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int a,b;
    cin>>a>>b;
    if(a==b)
        cout<<a+b;
    else{
        int mx=max(a,b);
        int k=(mx-1)+mx;
        cout<<k;
    }
}
