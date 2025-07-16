#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#include <cstdlib> 
#include <math.h>
#include<cstdio>
#include<cstring>
#define FOR(I, A, B) for (ll I = (A); I <= (B); I++)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fo(i,n) for(ll i=0;i<n;i++)
#define sz(a) ll((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x,y,z,q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #q << " = " << q << endl
#define scan(char_array) scanf("%[^\n]s",&char_array);
struct three{
	ll a,b,c;

};

int main(){
	ll n,q;
	IOS
	cin>>n>>q;
	std::vector<three> v;
	ll aa,bb,cc;
	auto compare=[&](three a,three b){
		return a.a<b.a;

	};
	fo(i,n){
		three tmp;
		cin>>aa>>bb>>cc;
		tmp.a=cc;
		ll hi,lo;
		if(bb-1>=cc){
			hi=bb-1-cc;

		}
		else hi=-1;
		lo=max((ll)0,aa-cc);
		tmp.b=lo;
		tmp.c=hi;
		v.pb(tmp);



	}
	map<ll,ll> d;
	sort(all(v),compare);
	set<ll> st;
	fo(i,q){
		cin>>aa;
		d[aa]=-1;

		st.insert(aa);
	}
	for(auto kk:v){
		//dbg3(kk.a,kk.b,kk.c);
		std::vector<ll> out;
		auto it=st.lower_bound(kk.b);
		while(it!=st.end()){
			ll our=*it;
			if(our>=kk.b&&our<=kk.c){
				out.pb(our);


			}
			else break;
			it++;
		}
		for(auto pp:out){
			d[pp]=kk.a;

			st.erase(pp);

		}
	}
	for(auto ii:d){
		cout<<ii.second<<endl;
	}

}


