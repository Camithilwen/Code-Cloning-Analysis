#include<bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define w(x)  int x; cin>>x; while(x--)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define watch3(x,y,z) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<" and "<<(#z)<<" is "<<(z)<<"\n"
#define watch4(x,y,z,q) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<" and "<<(#z)<<" is "<<(z)<<" and "<<(#q)<<" is "<<(q)<<"\n"
#define MOD 1000000007
#define INF 1000000007;
#define F first
#define S second
#define pb(x) push_back(x);


#define ll  long long
#define all(c) (c).begin(),(c).end()
#define endl "\n"

typedef vector<int> vl;
typedef vector< vl > vvl;
typedef pair< int, int> pll;
typedef map< int, int> mll;


#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif





void c_p_c()
{
#ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void parray(int a[],int n){
    for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int i,n,m,k,c=0,sum=0;
    c_p_c();
    // cout<<c<<endl;
    string s;
    cin>>s;
    n = (int)s.size();

    int ans =753;
    int mini=INF;
    for (int i = 0,j=2; i <=n-3; i++)
    {
    	/* code */
    	// j++;
    	string str=s.substr(i,3);

    	// watch(str-"0");
    	int x = stoi(str);
    	// debug(x);
    	mini=min(mini,abs(ans-x));


    }
    cout<<mini<<endl;
    return 0;
}

