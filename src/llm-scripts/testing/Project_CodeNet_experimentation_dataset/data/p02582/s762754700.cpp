#include<bits/stdc++.h>
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

#define N 4e7
#define nl "\n"
#define f first
#define s second
#define pi acos(-1.0)
#define MOD 1000000007
#define pb push_back
#define vector<int> VI;
#define vector<long long> VII;

typedef long long ll;
typedef double db;

using namespace std;

int main()
{
    io;
    //freopen("in.txt" , "r" , stdin);
    //freopen("out.txt" , "w" , stdout);

    ///Let the showdown begin

    string str;
    int cnt;
    
    cin >> str;

    if(str[0] =='R' && str[1] == 'R' && str[2] == 'R')
        cnt = 3;
    else if((str[0] =='R' && str[1] == 'R' && str[2] == 'S') || (str[0] =='S' && str[1] == 'R' && str[2] == 'R'))
        cnt = 2;
    else if((str[0] =='S' && str[1] == 'S' && str[2] == 'S'))
        cnt = 0;
    else
        cnt = 1;

    cout << cnt << nl;

    ///Happily DONE
    return 0;
}
