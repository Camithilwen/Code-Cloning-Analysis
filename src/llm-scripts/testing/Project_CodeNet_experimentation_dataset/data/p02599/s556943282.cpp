#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i = 0;i < n;i++)

/*
*	verified : http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4713284#1
*	last revised : 29.July.2020 
 */
template<class T> class BIT {
private:
	int n;
	vector<T> dat;//[1,n]
public:
	BIT(int maxn, int _n) {
		dat.assign(maxn + 1, 0);
		n = _n;
	}
	T sum(int i) {
		T res = 0;
		while (i > 0) {
			res += dat[i];
			i -= i & -i;
		}
		return res;
	}
	void add(int i, T x) {
		while (i <= n) {
			dat[i] += x;
			i += i & -i;
		}
	}
};
#define maxn 500050
#define F first
#define S second
struct range{
  int l,r,id;
  range(){}
  range(int l,int r,int id):l(l),r(r),id(id){}
};
bool comp(range& a,range& b){
  return a.r < b.r;
}
int main(){
  cin.tie(0);ios::sync_with_stdio(false);  
  int N,Q;cin >> N >> Q;
  vector<int> c(N+1);
  for(int i=1;i<=N;i++)cin>>c[i];
  vector<range> a(Q);
  for(int i=0;i<Q;i++){
    int l,r;cin >> l >> r;
    a[i] = range(l,r,i);
  }
  sort(a.begin(),a.end(),comp);
  BIT<int> bit(maxn,maxn);
  vector<int> good(maxn,0);
  vector<int> ans(Q,0);
  int i = 0,j = 1;
  for(;i < Q;i++){
    for(;j <= a[i].r;j++){
      if(good[c[j]] == 0){
        bit.add(j,1);
      }else{
        bit.add(good[c[j]],-1);
        bit.add(j,1);
      }
      good[c[j]] = j;
    }
    if(a[i].l == 1) ans[a[i].id] = bit.sum(a[i].r);
    else ans[a[i].id] = bit.sum(a[i].r) - bit.sum(a[i].l-1);
  }
  for(int i=0;i<Q;i++)cout << ans[i] << '\n';
}
