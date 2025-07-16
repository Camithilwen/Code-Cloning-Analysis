#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define REP(i , n) for(Long i = 0; i < (Long)n ; i++)
#define fore(i, a, b) for (Long i = a, to = b; i < to; i++)
#define foref(i, a, b) for (Long i = b - 1, to = a; i >= to; i--)
#define all(v) v.begin(), v.end()
#define SZ(v) (int)v.size()
#define pb push_back

using namespace std;
typedef long long Long;
typedef pair<Long, Long> Pair;

const int MX=(2e5);
const Long INF=(1e18);
Long A[MX+2];
Long acum[MX+2];
Long acum2[MX+2];
int n;
set<Long> S1,S2;
Long ans = INF;
void solve(vector<Pair> izq,vector<Pair> der){
	fore(i,0,SZ(izq)){
		fore(j,0,SZ(der)){
			vector<Long> asd;
			asd.pb(izq[i].first);
			asd.pb(izq[i].second);
			asd.pb(der[j].first);
			asd.pb(der[j].second);
			//fore(k,0,4)cout<<asd[k]<<(char)(k+1==4?10:32);
			sort(all(asd));
			ans = min(ans,asd[3] - asd[0]);
		}
	}
}

void show(){
	cout<<"der"<<endl;
	for(auto x:S1){
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<"izq"<<endl;
	for(auto x:S2){
		cout<<x<<" ";
	}
	cout<<endl;
}

void prueba(Long current){
	//show();
	Long search1 = current/2;
	auto it = S1.lower_bound(search1);
	vector<Pair> izq;
	if(it!=S1.end()){
		Long p = (*it);
		Long q = current - p;
		izq.pb({p,q});
	}
	if(it!=S1.begin()){
		it--;
		Long p = (*it);
		Long q = current - p;
		izq.pb({p,q});
	}
	
	Long total = acum[n-1] - current;
	Long search2 = total/2;
	auto it2 = S2.lower_bound(search2);
	vector<Pair> der;
	if(it2!=S2.end()){
		Long p = (*it2);
		Long q = total - p;
		der.pb({p,q});
	}
	if(it2!=S2.begin()){
		it2--;
		Long p = (*it2);
		Long q = total - p;
		der.pb({p,q});
	}
	solve(izq,der);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	fore(i,0,n) cin>>A[i];
	acum[0] = A[0];
	fore(i,1,n) acum[i]=A[i] + acum[i-1];
	
	acum2[n-1] = A[n-1];
	foref(i,0,n-1){
		acum2[i] = acum2[i+1] + A[i];
	}
	fore(i,0,n) S2.insert(acum2[i]);
	
	fore(i,0,n){
		S1.insert(acum[i]);
		S2.erase(acum2[i]);
		if(i>0 && i<n-2)prueba(acum[i]);
	}
	cout<<ans<<endl;

	return 0;
}
