#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
int main(){
	ll n;
	cin>>n;
	stack<char> st;
	while(n!=0){
		n--;
		st.push('a'+n%26);
		n/=26;
	}
	while(!st.empty()){
		cout<<st.top();
		st.pop();
	}
	return 0;
}