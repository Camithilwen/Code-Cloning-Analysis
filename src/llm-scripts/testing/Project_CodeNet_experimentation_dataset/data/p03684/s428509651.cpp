#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <numeric>
#include <queue>
using namespace std;
#define loop(i,N) for(ll (i)=0; (i)<(N);++(i))
struct TEMP_OMAZINAI_ { TEMP_OMAZINAI_() { std::ios::sync_with_stdio(false); std::cin.tie(0); } } TEMP__omazinai_instance__;
#define INF ((1LL<<61) + (1<<29))
#define YesNo(x) {std::cout << ((x)?"Yes":"No") << std::endl;}
#define YESNO(x) {std::cout << ((x)?"YES":"NO") << std::endl;}
#define OddEven(x) {std::cout << ((x)%2?"Odd":"Even") << std::endl;}
#define ODDEVEN(x) {std::cout << ((x)%2?"ODD":"EVEN") << std::endl;}
typedef long long int ll;
ll my_gcd(ll a, ll b) { return b ? my_gcd(b, a%b) : a; };
void TEMP_INPUT_IMPL_() {};
template <class T, class... Args> void TEMP_INPUT_IMPL_(T& dest, Args&... args) { cin >> dest; TEMP_INPUT_IMPL_(args...); }
void TEMP_OUTPUT_IMPL_() {};
template <class T, class... Args> void TEMP_OUTPUT_IMPL_(T dest, Args... args) { cout << dest << (sizeof...(Args) ? " " : ""); TEMP_OUTPUT_IMPL_(args...); }
#define in(type, ...) type __VA_ARGS__; TEMP_INPUT_IMPL_(__VA_ARGS__)
#define in_v(type, name, cnt) vector<type> name(cnt); loop(i, cnt) cin >> name[i];
#define sort_v(v) std::sort(v.begin(), v.end())
#define rsort_v(v) std::sort(v.rbegin(), v.rend())
#define unique_v(v) v.erase(std::unique(v.begin(), v.end()), v.end()) //必ずソート後に実行
#define out(...) (TEMP_OUTPUT_IMPL_(__VA_ARGS__), std::cout<<std::endl)
#define set_fix(x) ((std::cerr<<std::fixed<<std::setprecision(x)),(std::cout<<std::fixed<<std::setprecision(x)))
//小さい方に寄る
#define space_op(x, y, a, b, c) ([](auto x_, auto y_, auto a_, auto b_, auto c_){if(x_<y_)return a_;if(x_>y_)return c_;return b_;}(x,y,a,b,c))
#define space_out(x, y, a, b, c) out(space_op(x, y, a, b, c))
 
 // ^^^ Template ^^^ //

struct UnionFind{
	vector<ll> parent;
	vector<ll> size;
	UnionFind() = delete;
	UnionFind(ll n) : parent(n), size(n, 1){
		loop(i, n)
			parent[i] = i;
	}

	int find(ll x) {
		if(parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}

	void unite(ll x_, ll y_){
		ll x = find(x_);
		ll y = find(y_);
		if(x==y) return ;
		if(size[x] < size[y]) swap(x, y);
		parent[y] = x;
		size[x] += size[y];
	}

	bool same(ll x, ll y){
		return find(x) == find(y);
	}
};

int main() {
	in(ll, N);
	vector<pair<ll, ll>> xv(N), yv(N);
	vector<pair<ll, pair<ll, ll>>> ev;
	ev.reserve(N*3);
	//set<ll> u;
	ll ans = 0;
	loop(i, N){
		in(ll, x, y);
		xv[i] = {x, i};
		yv[i] = {y, i};
	}
	sort_v(xv);
	sort_v(yv);
	loop(i, N-1){
		// x
		ev.push_back({
			xv[i+1].first - xv[i].first,
			make_pair(xv[i].second, xv[i+1].second)
		});
		ev.push_back({
			xv[i+1].first - xv[i].first,
			make_pair(xv[i+1].second, xv[i].second)
		});
		// y
		ev.push_back({
			yv[i+1].first - yv[i].first,
			make_pair(yv[i].second, yv[i+1].second)
		});
		ev.push_back({
			yv[i+1].first - yv[i].first,
			make_pair(yv[i+1].second, yv[i].second)
		});
	}
	sort_v(ev);
	UnionFind uf(N);
	for(auto e : ev){
		if(!uf.same(e.second.first, e.second.second)){
			ans += e.first;
			uf.unite(e.second.first, e.second.second);
		}
	}
	out(ans);
}

