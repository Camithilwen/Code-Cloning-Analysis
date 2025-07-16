
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int h,w,a[200000+1],b[200000+1];
multiset<int> s;
set<mp> se;
int main(){
	R2(h,w);
	rb(i,1,h)
		R2(a[i],b[i]);
	rb(i,1,w)
		s.insert(0),se.insert(II(i,i));
	set<mp> :: IT l,r,nex;
	rb(i,1,h){
		l=se.lower_bound(II(a[i],-INF));
		r=se.upper_bound(II(b[i],INF));
		if(r!=se.begin()&&l!=se.end()&&l!=r){
			r--;
			int save=(*r).SEC;
			while(1){
//				cout<<"E:"<<(*l).FIR<<","<<(*l).SEC<<endl;
				if(l==r){
					s.erase(s.lower_bound((*l).FIR-(*l).SEC));
					se.erase(l);
					if(b[i]!=w){
						se.insert(II(b[i]+1,save));
//						cout<<"I:"<<b[i]+1<<","<<save<<endl;
						s.insert(b[i]+1-save);
					}
					break;
				}
				l++;
				nex=l;
				l--;
				s.erase(s.lower_bound((*l).FIR-(*l).SEC));
				se.erase(l);
				l=nex;
			}
			
		}
		if(s.empty()) cout<<"-1\n";
		else cout<<(*s.begin())+i<<endl;
	}
	return 0;
}
