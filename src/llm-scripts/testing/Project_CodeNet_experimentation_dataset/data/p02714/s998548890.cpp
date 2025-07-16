//Only the Creator has given me strength!🖤
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<bitset>
typedef long long ll;
#define pi 3.1415926535897931159979635
#define pb push_back
#define vctr vector<int>
#define vvtr vector<vctr>
int mod=1e9+7;
using namespace std;
void fastio() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fastio();
    int s;
    ll g=0;
    string a;
    cin>>s>>a;
    ll r=0,gr=0,b=0,k,l;
    for(int i=0; i<s; i++) {
        if(a[i]=='R') r++;
        else if(a[i]=='G') gr++;
        else b++;
        for(int j=0; j<s; j++) {
            k=2*j+i;
            l=j+i;
            if(k>=s) break;
            if(a[i]!=a[l] && a[i]!=a[k] && a[l]!=a[k])
                g++;
        }
    }
    ll ans=r*gr*b-g;
    cout<<ans<<"\n";
    return 0;
}