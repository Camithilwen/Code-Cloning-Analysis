
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <cctype>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <cassert>
#include <iomanip>

using namespace std;

#define pb push_back
typedef long long ll;
typedef complex<int> P;
typedef pair<int, int> Pii;


struct st{
	string name;
	double a;

	st(){}
	st(string n, double a) : name(n), a(a) {}
	bool operator< (const st &s)const{
		return (this->a == s.a) ? this->name < s.name : this->a > s.a;
	}
};

bool solve(int n){
	vector<st> vst;
	for(int i=0;i<n;i++){
		string l;
		int p, a, b, c, d, e, f, s, m;
		cin>> l>> p>> a>> b>> c>> d>> e>> f>> s>> m;
		int t, money;
		t = a + b + c + (d + e) * m;
		money = m * f * s - p;
		st tmp(l, (double)money/t);
		vst.pb(tmp);
	}
	sort(vst.begin(),vst.end());
	for(int i=0;i<vst.size();i++){
		cout<< vst[i].name<<  endl;
	}
	cout<< "#"<< endl;
	
	return true;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(10);
	
	int n;
	while(cin>>n, n){
		solve(n);
	}
	return 0;
}

 