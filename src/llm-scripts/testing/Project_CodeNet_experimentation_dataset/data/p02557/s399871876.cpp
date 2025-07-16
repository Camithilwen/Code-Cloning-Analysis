#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define nl cout<<"\n"
#define db(x) cout<<x<<" "
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define fk(a,b) for(int k=a;k<b;k++)
#define F first
#define S second
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
#define mxsize (int)1e6
ll fastexp(ll a,ll n,ll nod){
    if(nod==0)	nod=LLONG_MAX;
    ll ans=1;
    while(n){
        if(n&1)
            ans=(ans*a)%nod;
        a=(a*a)%nod;
        n>>=1;
    }
    return ans;
}
void fun(){
    int n;
    cin>>n;
    int a[n],b[n];
    fi(0,n) cin>>a[i];
    fi(0,n) cin>>b[i];
    reverse(b,b+n);
    int i=0,j=n-1;
    int k=0;
    while(k<n){
        if(a[k]==b[k]){
            if(i!=-1&&(a[i]==a[k]||b[i]==a[k])){
                i=-1;
            }
            else if(i!=-1){
                swap(b[i++],b[k]);
            }
            if(i==-1&&(a[j]==a[k]||b[j]==a[k])){
                j=-1;
            }
            else if(i==-1){
                swap(b[j--],b[k]);
            }
            if(i==-1&&j==-1){
                cout<<"No\n";
                return ;
            }
        }
        k++;
    }
    cout<<"Yes\n";
    fi(0,n) db(b[i]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("/ATOM/input.txt", "r", stdin);
        freopen("/ATOM/output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--){
        fun();
    }
}