#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    int n,q;
    string s;
    cin >> n >> q >> s;
    vector<int> cnt(n,0);
    repi(i,n,1){
        if(s[i-1] == 'A' && s[i] == 'C')cnt[i]++;
        cnt[i] += cnt[i - 1];
    }
    repi(i,q,0){
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        cout << cnt[r] - cnt[l] << endl;
    }
    return 0;
}