#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);

    int a,b;
    cin>>a>>b;
    a--;
    b--;
    cout<<(b+a-1)/a<<endl;
    return 0;
}