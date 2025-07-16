#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5 ;
const int INF = 1e9 + 1e5 + 2;
const int mod= 1e9+7;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define what_is(x) cerr << #x << " = " << x << endl;
#define eps 1e-15
#define F first
#define S second
typedef long long ll;
ll fib[100006];
int main()
{
    fastIO
    string s;
    cin>>s;
    int a=s[0]-'0';
    int b=s[1]-'0';
    int c=s[2]-'0';
    int d=s[3]-'0';
    if (a+b+c+d==7)
        cout<<a<<"+"<<b<<"+"<<c<<"+"<<d<<"="<<7;
    else if (a-b-c-d==7)
        cout<<a<<"-"<<b<<"-"<<c<<"-"<<d<<"="<<7;
    else if (a-b+c+d==7)
        cout<<a<<"-"<<b<<"+"<<c<<"+"<<d<<"="<<7;
    else if (a+b-c+d==7)
        cout<<a<<"+"<<b<<"-"<<c<<"+"<<d<<"="<<7;
    else if (a+b+c-d==7)
        cout<<a<<"+"<<b<<"+"<<c<<"-"<<d<<"="<<7;
    else if (a-b-c+d==7)
        cout<<a<<"-"<<b<<"-"<<c<<"+"<<d<<"="<<7;
    else if (a-b+c-d==7)
        cout<<a<<"-"<<b<<"+"<<c<<"-"<<d<<"="<<7;
    else  if (a+b-c-d==7)
        cout<<a<<"+"<<b<<"-"<<c<<"-"<<d<<"="<<7;




}
