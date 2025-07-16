#include <bits/stdc++.h> 
#include<cmath>
#include<string>
#define pb push_back
//#define x first
//#define y second
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
//void __print(long long x) {cerr << x;}
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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
// look for  all edge cases
//search for a pattern



signed main() {    
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n);
	
	for(int i =0 ; i < n ; i++)cin >> v[i];
	
	set<int> s;
	map<int,int> m;
	
	for(int i =0 ; i < n; i++){
		int temp;
		cin >> temp;
		m[temp] += 1;
		s.insert(temp);
	} 
	
	int l = 0;
	bool ok = true;
	vector<int> ans(n);
	
	for(int i= 0 ; i < n; i++){
		int val = v[i];
		auto beg = *s.begin();
		auto en = *s.rbegin();
		if(beg != en){
			if(val == beg){
				m[en] -= 1;
				if(m[en] == 0){
					s.erase(en);
				}
				ans[i] = en;
			}
			else{
				m[beg] -= 1;
				if(m[beg] == 0){
					s.erase(beg);
				}
				ans[i] = beg;
			}
		}
		else if(beg == en && en != val){
			m[beg] -= 1;
			ans[i] = beg;
			if(m[beg] == 0){
				s.erase(beg);
			}
			
		}
		else{
			m[beg] -= 1;
			bool found = false;
			while(l != i){
				
				if(v[l] != beg && ans[l] != beg){
					int temp = ans[l];
					ans[l] = beg;
					ans[i] = temp;
					l++;
					found = true;
					break;
				}
				l++;
			}
			
			if(found){
				if(m[beg] == 0){
					s.erase(beg);
				}
			}
			else{
				ok = false;
			}
			
		}
	} 
	
	if(!ok)
		cout<<"No";
	else{
		cout<<"Yes\n";
		for(auto it : ans){
			cout<< it << " ";
		}
	}
	 
	return 0;
}
