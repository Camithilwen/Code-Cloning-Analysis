#include <bits/stdc++.h>
#define rep(i, a) for (int i = (int)0; i < (int)a; ++i)
#define rrep(i, a) for (int i = (int)a - 1; i >= 0; --i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define RREP(i, a, b) for (int i = (int)a - 1; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define popcount __builtin_popcount
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

template <class T>
inline bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

ll gcd(ll n, ll m)
{
	ll tmp;
	while (m != 0)
	{
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m)
{
	return abs(n) / gcd(n, m) * abs(m); //gl=xy
}

using namespace std;

template<typename T>
struct BIT{
  //0オリジンで与える
  vector<T>bit;
  int N;

  BIT(int n):N(n){
    bit.assign(++n,0);
  }

  T sum(int i){
    T s=0;
    ++i;//0オリジンに対応させる
    while(i>0){
      s+=bit[i];
      i-=i&-i;//iから最後の1のビットを減算
    }
    return s;
  }

  void add(int i,T x){
    ++i;//0オリジンに対応させる
    while(i<(int)bit.size()){
      bit[i]+=x;
      i+=i&-i;
    }
  }

  T Lower_bound(T k){
    if(k<=0)
      return 0;
    T x = 0;
    T mul = 1;
    while (mul<N){
      mul *= 2;
    }
    for (T i = mul; i > 0;i/=2){
      if(x+i<=N&&bit[x+i]<k){
        k -= bit[x + i];
        x += i;
      }
    }
    return x;
  }
};

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int>used(n,-1);
	vector<int>c(n);
	vector<pair<int,int>>v;
	rep(i,n){
		cin>>c[i];
		c[i]--;
		if(used[c[i]]!=-1){
			v.eb(used[c[i]],i);
			used[c[i]]=i;
		}
		else {
			used[c[i]]=i;
		}
	}
	vector<pair<pair<int,int>,int>>query(q);
	rep(i,q){
		cin>>query[i].first.first>>query[i].first.second;
		query[i].first.first--;
		query[i].first.second--;
		query[i].second=i;
	}
	if(!v.empty())sort(rall(v));
	sort(rall(query));
	vector<int>ans(q);
	// for(auto x:v){
	// 	cout<<x.first<<" "<<x.second<<"\n";
	// }
	int pos=0,qpos=0;
	BIT<int>tree(n);
	for(int i=n-1;i>=0;--i){
		while(pos<v.size()&&v[pos].first==i){
			tree.add(v[pos].second,1);
			pos++;
		}
		while(qpos<q&&query[qpos].first.first==i){
			ans[query[qpos].second]=(query[qpos].first.second-query[qpos].first.first+1)-tree.sum(query[qpos].first.second);
			qpos++;
		}
	}
	rep(i,q){
		cout<<ans[i]<<"\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
