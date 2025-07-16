#include <bits/stdc++.h>
using namespace std;


int main() {

    int a,b,c;
    cin>>a>>b>>c;


    if(c>=a&&c<=b||c>=b&&c<=a)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}