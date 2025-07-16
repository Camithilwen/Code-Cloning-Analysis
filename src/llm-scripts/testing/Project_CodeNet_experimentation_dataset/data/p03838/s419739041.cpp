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
    ll x,y;
    cin >> x >> y;
    if(x*y > 0){
        if(x > y){
            cout << min(llabs(x)+llabs(y)+1,llabs(llabs(x)-llabs(y))+2)<< endl;
        }else{
            cout << y - x << endl;
        }
    }else if(x*y < 0){
        cout << llabs(llabs(x)-llabs(y))+1 << endl;
    }else{
        if(x == y){
            cout << 0 << endl;
        }else if(x == 0){
            if(y > 0){
                cout << y << endl;
            }else{
                cout << llabs(y)+1 << endl;
            }
        }else{
            if(x > 0){
                cout << x+1 << endl;
            }else{
                cout << -x << endl;
            }
        }
    }
    return 0;
}