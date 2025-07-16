// #include<bits/stdc++.h>
// using namespace std;

// int main(){
// 	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// 	int tc;
// 	cin >> tc;
// 	while(tc--){
// 		string s;
// 		cin >> s;
// 		int count_0 = 0, count_1 = 0;
// 		for(char ch : s)
// 			count_0 += 1 - ch + '0', count_1 += ch - '0';
// 		int ans = min(count_0, count_1);
// 		int c0 = 0, c1 = 0, n = s.size();
// 		for(int i = 0; i < n - 1; i++){
// 			c0 += 1 - s[i] + '0', c1 += s[i] - '0';
// 			ans = min(ans, c0 + count_1 - c1);
// 			ans = min(ans, c1 + count_0 - c0);
// 		}
// 		cout << ans << '\n';
// 	}
// }
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
//increase stack size
#pragma comment(linker, "/STACK:16777216")

ll mxm() {return LLONG_MIN;}
template<typename... Args>
ll mxm(ll a, Args... args) { return max(a,mxm(args...)); }

ll mnm() {return LLONG_MAX;}
template<typename... Args>
ll mnm(ll a, Args... args) { return min(a,mnm(args...)); }

template<class T> ostream& operator<<(ostream& os,vector<T> V){
	os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";
}
template<class L,class R> ostream& operator<<(ostream& os,pair<L,R> P){
	return os<<"("<<P.first<<","<<P.second<<")";
}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){
	cout<<name<<" : "<<arg1<<endl;
}
template <typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){
	const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);
}
#else
#define trace(...) 1
#endif

#define ld long double
#define pll pair<ll,ll>
#define ii pair<int,int>
#define vll vector<ll>
#define vii vector<ii>
#define vi vector<int>
#define vpll vector<pll>
#define vld vector<ld>
#define vvld vector<vld>
#define vvi vector<vi>
#define vvll vector<vll>
#define vvpll vector<vpll>
#define vvii vector<vii>
#define I insert
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define all(x)	x.begin(),x.end()

const int mod=1e9+7;
// 128 bit: __int128
inline int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
inline int sub(int a,int b){a-=b;if(a<0)a+=mod;return a;}
inline int mul(int a,int b){return (a*1ll*b)%mod;}
inline int power(int a,int b){int rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
inline int inv(int a){return power(a,mod-2);}

struct compare{
	bool operator() (const int &a,const int &b) const{
		return a>b;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout<<setprecision(25);
	int n;
	cin >> n;
	vector<string> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	vector<pair<int, int> > balances, negative_balances;
	for(int i = 0; i < n; i++){
		int tot = 0, mn = 0;
		for(auto j : v[i]){
			if(j == '(')
				tot++;
			else tot--;
			mn = min(mn, tot);
		}
		if(tot < 0)
			negative_balances.push_back({tot - mn, -tot});
		else
			balances.push_back({-mn, tot});
	}
	sort(all(balances));
	sort(all(negative_balances));
	reverse(all(negative_balances));
	int mn_neg_sum = 0, cur_neg_sum = 0;
	for(auto i : negative_balances){
		mn_neg_sum = max(mn_neg_sum, cur_neg_sum + i.first + i.second);
		cur_neg_sum += i.second;
	}
	int mn_seen = 0;
	for(auto i : balances)
		if(i.first > mn_seen){
			cout << "No" << endl;
			return 0;
		}
		else mn_seen += i.second;
	if(mn_seen != cur_neg_sum || mn_seen < mn_neg_sum){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}