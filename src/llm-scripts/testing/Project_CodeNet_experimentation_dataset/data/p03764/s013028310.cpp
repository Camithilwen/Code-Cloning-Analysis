#include "bits/stdc++.h"
using namespace std;typedef long long lint;typedef vector<lint> liv;
//#define rep(i,n) for(int i=0;i<n;++i)
#define all(v) v.begin(),v.end()
#define linf 1152921504606846976
#define MAXN 100010
#define md 1000000007//998244353

#define pb push_back
#define _vcppunko4(tuple) _getname4 tuple
#define _getname4(_1,_2,_3,_4,name,...) name
#define _getname3(_1,_2,_3,name,...) name
#define _trep2(tuple) _rep2 tuple
#define _trep3(tuple) _rep3 tuple
#define _trep4(tuple) _rep4 tuple
#define _rep1(n) for(lint i=0;i<n;++i)
#define _rep2(i,n) for(lint i=0;i<n;++i)
#define _rep3(i,a,b) for(lint i=a;i<b;++i)
#define _rep4(i,a,b,c) for(lint i=a;i<b;i+=c)
#define _trrep2(tuple) _rrep2 tuple
#define _trrep3(tuple) _rrep3 tuple
#define _trrep4(tuple) _rrep4 tuple
#define _rrep1(n) for(lint i=n-1;i>=0;i--)
#define _rrep2(i,n) for(lint i=n-1;i>=0;i--)
#define _rrep3(i,a,b) for(lint i=b-1;i>=a;i--)
#define _rrep4(i,a,b,c) for(lint i=a+(b-a-1)/c*c;i>=a;i-=c)
template<class T>
istream& operator>>(istream& is,vector<T>& vec);
template<class T,size_t size>
istream& operator>>(istream& is,array<T,size>& vec);
template<class T,class L>
istream& operator>>(istream& is,pair<T,L>& p);
template<class T>
ostream& operator<<(ostream& os,vector<T>& vec);
template<class T,class L>
ostream& operator<<(ostream& os,pair<T,L>& p);
template<class T>
istream& operator>>(istream& is,vector<T>& vec){ for(T& x: vec) is>>x;return is; }
template<class T,class L>
istream& operator>>(istream& is,pair<T,L>& p){ is>>p.first;is>>p.second;return is; }
//template<class T>
//ostream& operator<<(ostream& os,vector<T>& vec){ os<<vec[0];rep(i,1,vec.size())os<<' '<<vec[i];return os; }
//template<class T>
//ostream& operator<<(ostream& os,deque<T>& deq){ os<<deq[0];rep(i,1,deq.size())os<<' '<<deq[i];return os; }
template<class T,class L>
ostream& operator<<(ostream& os,pair<T,L>& p){ os<<p.first<<" "<<p.second;return os; }

inline void in(){}
template <class Head,class... Tail>
inline void in(Head&& head,Tail&&... tail){ cin>>head;in(move(tail)...); }
template <class T>
inline bool out(T t){ cout<<t<<'\n';return 0; }
inline bool out(){ cout<<'\n';return 0; }
template <class Head,class... Tail>
inline bool out(Head head,Tail... tail){ cout<<head<<' ';out(move(tail)...);return 0; }

#define rep(...) _vcppunko4((__VA_ARGS__,_trep4,_trep3,_trep2,_rep1))((__VA_ARGS__))
#define rrep(...) _vcppunko4((__VA_ARGS__,_trrep4,_trrep3,_trrep2,_trrep1))((__VA_ARGS__))
#define lin(...) lint __VA_ARGS__;in(__VA_ARGS__)
#define stin(...) string __VA_ARGS__;in(__VA_ARGS__)
#define vin(type,name,size) vector<type> name(size);in(name)

int main(){
	lint xs=0,ys=0,cur=0;
	lin(n,m);
	vin(lint,x,n);vin(lint,y,m);
	//rep(n)x[i]+=1e9;rep(m)y[i]+=1e9;
	rep(n-1){
		cur+=x[n-i-1]-x[i]+md;cur%=md;
		xs+=cur;xs%=md;
	}cur=0;
	rep(m-1){
		cur+=y[m-i-1]-y[i]+md;cur%=md;
		ys+=cur;ys%=md;
	}lint ans=(xs*ys)%md;
	cout<<ans<<endl;
}
