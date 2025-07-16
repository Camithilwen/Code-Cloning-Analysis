#include<bits/stdc++.h>
#define ll long long
#define pii_ pair<int,int>
#define mp_ make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define show1(a) cout<<#a<<" = "<<a<<endl
#define show2(a,b) cout<<#a<<" = "<<a<<"; "<<#b<<" = "<<b<<endl
using namespace std;
const ll INF = 1LL<<60;
const int inf = 1<<30;
const int maxn = 2e5+5;
inline void fastio() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int a[55];

int main()
{
    fastio();
    int n,k;
    cin>>n>>k;
    rep(i,1,n) cin>>a[i];
    int ans = 0;
    rep(i,0,min(k,n)){
        rep(L,0,i){
            int R = i - L;
            multiset<int> st;
            rep(j,1,L) st.insert(a[j]);
            rep(j,1,R) st.insert(a[n-j+1]);
            rep(j,1,k-i){
                if(st.size()==0) break;
                auto it = st.begin();
                int v = *it;
                if(v >= 0) break;
                st.erase(it);
            }
            int tmp = 0;
            for(int x:st) tmp+=x;
            ans = max(ans,tmp);
        }
    }
    cout<<ans<<endl;
    return 0;
}
