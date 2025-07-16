#include<bits/stdc++.h>
using namespace std;
 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MP make_pair
#define pb push_back
#define ff first
#define ss second
#define sz(x) x.size()
#define all(c) c.begin(),c.end()
#define int long long
#define fr(i,j,x) for(int i=j;i<x;i++)
#define rep(i,j,x) for(int i=j;i<=x;i++)
#define mem(x,val) memset(x,val,sizeof(x))
//#define endl '\n'
#define vi vector<int>
#define pii pair<int,int>
#define piii pair<int,pii>
 
const int mod=1e9+7;
const int N=1e5+10;
const int MAXN=2e6+10;
const int INF=1e18;

string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int a[N];

string getbase(int x,int b){
    string ans;
    int d;
    while(x){
        d=x%b;
        ans=char('0'+d)+ans;
        x/=b;
    }
    return ans;
}

string L,R;
int d,dp[10010][2][2][101];

int rec(int ind,int tlo,int thi,int rem){
    if(ind>=L.length()){
        if(rem==0){
            return 1;
        }
        return 0;
    }
    if(dp[ind][tlo][thi][rem]==-1){
        int blo=0;
        int bhi=9;
        if(tlo){
            blo=L[ind]-'0';
        }
        if(thi){
            bhi=R[ind]-'0';
        }
        int ans=0;
        for(int i=blo;i<=bhi;i++){
            int ntlo=tlo;
            int nthi=thi;
            if(i>L[ind]-'0'){
                ntlo=0;
            }
            if(i<R[ind]-'0'){
                nthi=0;
            }
            ans+=rec(ind+1,ntlo,nthi,(rem+i)%d);
            ans%=mod;
        }
        dp[ind][tlo][thi][rem]=ans;
    }
    return dp[ind][tlo][thi][rem];
}

void solve(){
    string l,r;
    l="1";
    cin>>r>>d;
    L=l;
    R=r;
    reverse(all(L));
    reverse(all(R));
    while(L.length()<R.length()){
        L+='0';
    }
    while(L.length()>R.length()){
        R+='0';
    }
    reverse(all(L));
    reverse(all(R));
    mem(dp,-1);
    cout<<rec(0,1,1,0)<<endl;
}


int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("inputf.in", "r", stdin);
    //     //freopen("outputf.in", "w", stdout);
    // #endif
    SPEED;
    int T=1;
    //cin>>T;
    int t1=1;
    while(true)
    {  
        //cout<<"Case #"<<t1<<": ";
        solve();
        t1++;
        if(t1>T)
            break;
    }
}

