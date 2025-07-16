#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define pi pair<int,int>
#define ff first
#define ss second
#define boost ios::sync_with_stdio(false);cin.tie(nullptr)
#include "string"
	

typedef tree<
   pair<int,int>, 
   null_type,
   less< pair<int,int> >,
   rb_tree_tag, 
   tree_order_statistics_node_update
>ordered_set; 

int32_t main(){
	int n,q;
	cin>>n>>q;
	array<int,3> a[n];
	for(int i=0;i<n;i++)
		cin>>a[i][1]>>a[i][2]>>a[i][0];
	sort(a,a+n);

	set<pair<int,int>>s;
	for(int i=0;i<q;i++){
		int x;
		cin>>x;
		s.insert({x,i});
	}

	int ans[q];
	memset(ans,-1,sizeof ans);
	for(int i=0;i<n;i++){
		int t1 = a[i][1] - a[i][0];
		int t2 = a[i][2] - a[i][0];

		auto l = s.lower_bound({t1,0ll});
		auto r = s.lower_bound({t2,0ll});
		/*cout<<l->ff<<" "<<l->ss<<endl;
		cout<<r->ff<<" "<<r->ss<<endl;
		cout<<t2<<" "<<t1<<endl<<endl;
		*/vector<pi>v;
		for(auto it=l;it!=r;it++){
			pi x = *it;
			//cout<<x.ff<<" "<<x.ss<<endl;
			ans[x.ss] = a[i][0];
			v.push_back(x); 
		}

		//print(v);
		for(auto &p :v)
			s.erase(p);
	}

	for(int i=0;i<q;i++)
		cout<<ans[i]<<endl;
}

