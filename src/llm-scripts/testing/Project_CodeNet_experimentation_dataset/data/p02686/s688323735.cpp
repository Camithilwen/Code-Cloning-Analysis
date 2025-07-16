#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}

pii get(string s){
	stack<char> st;
	pii ans = {0, 0};
	for(auto &c : s){
		if(c == '(')
			st.push(c);
		else{
			if(st.empty())
				ans.first++;
			else{
				st.pop();
			}
		}
	}

	ans.second = (int)st.size();

	return ans;
}

bool balanced(string &s){
	int bal = 0;
	for(auto &c : s){
		if(c == '(')
			bal++;
		else
			bal--;
		if(bal < 0)
			return false;
	}
	return bal == 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	int n;
	cin >> n;

	vector<pii> v1, v2;

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		pii x = get(s);

		if(x == pii(0, 0))
			continue;

		if(x.second > x.first)
			v1.push_back(x);
		else
			v2.push_back(pii(x.second, x.first));
	}

	sort(v1.begin(), v1.end());
	sort(v2.rbegin(), v2.rend());

	string s = "";

	for(auto &p : v1){
		for(int i = 0; i < p.first; i++)
			s += ")";
		for(int i = 0; i < p.second; i++)
			s += "(";
	}

	for(auto &p : v2){
		for(int i = 0; i < p.second; i++)
			s += ")";
		for(int i = 0; i < p.first; i++)
			s += "(";
	}


	if(balanced(s))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}