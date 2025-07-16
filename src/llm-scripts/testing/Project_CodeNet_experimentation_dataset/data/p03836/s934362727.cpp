#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int x,y,tx,ty;
    cin>>x>>y>>tx>>ty;
    int n=abs(x-tx);
    int m=abs(y-ty);
    cout<<string(n,'R')<<string(m,'U');
    cout<<string(n,'L')<<string(m,'D');
    cout<<'L'<<string(m+1,'U')<<string(n+1,'R')<<'D';
    cout<<'R'<<string(m+1,'D')<<string(n+1,'L')<<'U';
    cout<<endl;

    return 0;
}
