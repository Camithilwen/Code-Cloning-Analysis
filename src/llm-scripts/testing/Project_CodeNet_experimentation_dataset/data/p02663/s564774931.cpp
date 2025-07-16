#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h1,m1,h2,m2,k;
    cin>>h1>>m1>>h2>>m2>>k;
    int a=h2-h1;
    int b=m2-m1;
    int c=(a*60+b)-k;
    cout<<c<<endl;
    exit(0);
}
