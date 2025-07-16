#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int x; cin>>x;
	for (int i=x; i<=999; i++) {
		string cur=to_string(i);
		set<char> st(cur.begin(),cur.end());
		if (st.size()==1) {
			cout<<i<<endl;
		break;
		}
	}
	return 0;
}
