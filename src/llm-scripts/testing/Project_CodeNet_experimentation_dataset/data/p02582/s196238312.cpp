#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int inf = 1e9+7;
const int N = 1e6+9;

int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n;
    string s;
    cin>>s;
    int sum=0, mx=0;
    for(char ch: s) {
        if(ch=='R') sum++;
        else sum=0;
        mx = max(mx, sum);
    }
    cout<<mx<<endl;
    return 0;
}