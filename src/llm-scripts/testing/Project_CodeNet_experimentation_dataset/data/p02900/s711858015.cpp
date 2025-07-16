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
    ll a,b;
    vector<ll> num;
    cin >> a >> b;

    if(a==b&&a==1){
        cout << 1 << endl;
        return 0;
    }
    if(a<b){
        swap(a,b);
    }
    ll c=a;
    ll i;

    for(i=2;i*i<=c;++i){
        if(c%i!=0){
            continue;
        }
        while(c%i==0){
            c/=i;
        }
        num.push_back(i);
    }
    if(c!=1){
        num.push_back(c);
    }
    ssort(num);

    ll count=1;
    rep(i,num.size()){
        if(b>=num[i]){
            if(b%num[i]==0){
                count++;
            }
        }
    }
    cout << count << endl;
}