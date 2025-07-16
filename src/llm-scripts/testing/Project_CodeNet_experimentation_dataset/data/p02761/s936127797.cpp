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
using Graf_char=vector<vector<char>>;
using Graf_int=vector<vector<int>>;
#define MAX 100000

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> s(m),c(m);
    rep(i,m){
        cin >> s[i] >> c[i];
    }
    vector<int> num(n,-1);
    rep(i,m){
        if(num[s[i]-1]!=-1){
            if(num[s[i]-1]!=c[i]){
                cout << -1 << endl;
                return 0;
            }
        }
        else{
            num[s[i]-1]=c[i];
            if(s[i]-1==0&&c[i]==0&&n>1){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    rep(i,n){
        if(n>1&&i==0&&num[i]==-1){
            cout << 1;
        }else if(num[i]==-1){
            cout << 0;
        }else{
            cout << num[i];
        }
    }
    cout << endl;
}