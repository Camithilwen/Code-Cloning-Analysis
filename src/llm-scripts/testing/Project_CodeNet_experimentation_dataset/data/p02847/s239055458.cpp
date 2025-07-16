#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
#define MAX 10000000

int main()
{
    string s;
    cin >> s;
    if(s=="SUN"){
        cout << 7 << endl;
    }
    else if(s=="MON"){
        cout << 6 << endl;
    }
    else if(s=="TUE"){
        cout << 5 << endl;
    }
    else if(s=="WED"){
        cout << 4 << endl;
    }
    else if(s=="THU"){
        cout << 3 << endl;
    }
    else if(s=="FRI"){
        cout << 2 << endl;
    }
    else if(s=="SAT"){
        cout << 1 << endl;
    }
}