#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
long long const mod = 1000000007;

int n, x[3], v;
vector< vector<long long> > dp;

bool g(int mem, int a){
    int m = mem, sum = 0, prc = 2;
    if(a == x[2]) prc--;
    else sum = a;
    while(m > 0){
        int tmp = 1;
        while(m%2 == 0){
            m >>= 1;
            tmp++;
        }
        sum += tmp;
        if(sum == x[prc]){
            sum = 0;
            if(prc-- == 0) return false;
        }else if(sum > x[prc]) return true;
        m >>= 1;
    }
    return true;
}

long long f(int id, int mem){
    if(id == n) return 1;
    if(dp[id][mem] != -1) return dp[id][mem];
    long long res = 0;
    for(int a = 1; a <= 10; a++){
        if(g(mem, a)) res += f(id+1, ((mem<<a)+(1<<(a-1)))%v);
    }
    return dp[id][mem] = res % mod;
}

int main(void){
    cin >> n >> x[0] >> x[1] >> x[2];
    v = (1<<(x[0]+x[1]+x[2]-1));
    dp.assign(n, vector<long long>(v, -1));
    long long ans = 1;
    for(int i=0;i<n;i++) ans = ans * 10 % mod;
    ans += mod - f(0, 0);
    cout << ans%mod << endl;

}
