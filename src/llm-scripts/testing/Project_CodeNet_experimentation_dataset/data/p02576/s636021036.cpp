#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include<algorithm> 
#include <iomanip>
#include <math.h>
#include <iostream>
#include <bitset>
#include <map>

#define db double
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ld long double
#define maxn 5005
#define mod 998244353
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define vv(z,a,b) vector<vector<int>>z(a,vector<int>(b))
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(c) begin(c),end(c)
#define pp pair<int,int>
#define fix(n) fixed << setprecision(n)
#define gmax(a,b) __gcd(a,b)
#define gmin(a,b) a/__gcd(a,b)*b
using namespace std;
//obj;
class binary{
public:
    bool isOK(int index, int key,vi a) {
    if (a[index] >= key) return true;
    else return false;
}
int binary_search(int key,vi a) {
   
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid, key,a)) ok = mid;
        else ng = mid;
    }
    return ok;
}
}obj;

int main(){
int n,x,t;
cin>>n>>x>>t;
int b=n%x;
int a=n/x;
if(b!=0)a++;
int ans=t*a;
cout<<ans<<endl;

return 0;
 }
