#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	set<int> st;
	rep(i,n){
		int a; cin>>a;
		if(st.count(a)==1) st.erase(a);
		else st.insert(a);
	}
	cout<<st.size()<<endl;
}
