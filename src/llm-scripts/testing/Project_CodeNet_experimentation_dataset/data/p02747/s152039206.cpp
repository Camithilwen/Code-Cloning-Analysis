#include <bits/stdc++.h>
#define ll				long long int
#define fast			ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
#define vi 			vector<int>
#define vll 			vector<long long int>
#define all(v)			v.begin(),v.end()
const ll MOD = 1e9 + 7;
const ll INF = 10000000000000000;
const ll MAX_N = 1e5 + 7;
using namespace std;
//vector<bool> h(10000001,1);



int main(){
	string s;
	cin >> s;
	int n = (int)s.size();
	n/=2;
	string b="";
	for(int i =0;i<n;i++)
	b+="hi";
	//cout << b << '\n';
	if(b==s)cout << "Yes";
	else cout << "No";
}

