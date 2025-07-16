#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<pi> vpi;
typedef vector<string> vsi;
typedef map<ll, ll> mape;
#define rep(i, a, b) for(ll i=(ll)a;i<=(ll)b;i++)
#define per(i, a, b) for(ll i=(ll)a;i>=(ll)b;i--)
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define N 2100
#define MAX 1234567890
#define f first
#define s second
#define pb push_back
#define mkp make_pair
#define MOD 1000000007

int main()
{
    fastio;

    ll n;
    cin >> n;
    string s = "";
    while(n > 26){
        ll rem = n % 26;
        if(rem == 0) {
            s += 'z';
            rem = 26;
        }
        else s += ('a' + rem - 1);
        n = (n - rem) / 26;
    }
    s += ('a' + n - 1);
    reverse(s.begin(), s.end());

    cout << s << endl;

    return 0;
}
