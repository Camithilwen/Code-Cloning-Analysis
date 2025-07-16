#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<char>v[105];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int a,b,r=0,c=0;
    cin>>a>>b;
    for(int i=0; i<50; i++)
    {
        for(int j=0; j<100; j++)
            v[i].push_back('.');
    }
    for(int i=50; i<100; i++)
    {
        for(int j=0; j<100; j++)
            v[i].push_back('#');
    }
    a--,b--;
    for(int i=0; i<50 && b; i+=2)
    {
        for(int j=0; j<100 && b; j+=2)
        {
            v[i][j]='#';
            b--;
        }
    }
    for(int i=99; i>=50 && a; i-=2)
    {
        for(int j=0; j<100 && a; j+=2)
        {
            v[i][j]='.';
            a--;
        }
    }
    cout<<"100 100"<<endl;
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
            cout<<v[i][j];
        cout<<endl;
    }





    return 0;
}
