#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    vector<ll>a(n);
    vector<int>count(n,0);
    int zerocount;
    REP(i,n){
        cin >> a[i];
    }
    if(a[0]!=0){
        cout << 0 << endl;
        return 0;
    }

    ll answer=1;
    REP(i,n){
        if(a[i]==0){
            answer = (answer*(3-count[0]))%MOD;
        }
        else{
            if(count[a[i]]>=count[a[i]-1]){
                cout << 0 << endl;
                return 0;
            }
            answer = (answer*(count[a[i]-1]-count[a[i]]))%MOD;
        }
        count[a[i]]++;
        if(count[a[i]]>3){
            cout << 0 << endl;
            return 0;
        }
    }
    cout << answer << endl;
    return 0;
}