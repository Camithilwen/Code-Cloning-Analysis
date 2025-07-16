#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;cin>>a>>b;
    if (a==b)cout<<a*2;
    else cout <<max(a,b)*2-1<<endl;
}