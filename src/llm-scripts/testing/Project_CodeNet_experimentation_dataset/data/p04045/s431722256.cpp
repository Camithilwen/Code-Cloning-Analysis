//
//AtCoder Beginner Contest 042
//C
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <functional>
#include <cassert>
#include <bitset>

using namespace std;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define SIZE(x) (int)(x).size()
#define SIZEL(x) (ll)(x).size()
#define MSG(a) cout << #a << " " << a << endl;

using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;

const double PI = 3.14159265358979323846;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }            //最小公倍数

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> dislike(10, 0);
    REP(i, k) {
        int d;
        cin >> d;
        dislike[d]=1;
    }

    int likeMin = -1;
    REP(i, 10) {
        if (dislike[i]==0){
            likeMin = i;
            break;
        }
    }
    vector<int> ans(10010, -1);

    int over = -1;
    int nn = n;
    int pos = 0;
    while(nn>0){
        ans[pos]=nn%10;
        if (dislike[nn%10] == 1) over = pos;
        nn /= 10;
        pos++;
    }
    
    if (over == -1) {
        cout << n << endl;
        return 0;
    }

    REP(i, over) ans[i]=likeMin;
    FOR(i, over, pos){
        int like = -1;
        FOR(j, ans[i], 9){
            if (dislike[j]==0){
                like = j;
                break;
            }
        }
        if (like == -1){
            ans[i]=likeMin;
            if (ans[i+1]==-1) ans[i+1] = 1;
            else ans[i+1]++;
        }else{
            ans[i]=like;
            break;
        }
    }

    string sans = "";
    REP(i, ans.size()){
        if (ans[i]==-1) break;
        else sans = to_string(ans[i]) + sans;
    }
    cout << sans << endl;
    return 0;
}
