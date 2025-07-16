#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif




ll n, m;

struct numinfo {
	int digit;
	int match;
	int min_match;
	int n;
};


vector<numinfo> nums;


bool dfs( int i, int remain_match, int remain_keta ){
	if ( i == SZ(nums) ){
		eprintf( "remain=%d %d   ", remain_match, remain_keta );
		rep(k,SZ(nums)){
			eprintf( "%d ", (int)nums[k].n );
		}
		eprintf( "\n" );
		if ( remain_match == 0 && remain_keta <= 0 )
			return true;
		return false;
	}
	for ( int k = remain_match/nums[i].match; k >= 0; k-- ){
		nums[i].n = k;
		int creatable_keta = (remain_match-k*nums[i].match)/nums[i].min_match;
		if ( remain_keta-k-creatable_keta > 0 )
			continue;
		if ( dfs( i+1, remain_match-k*nums[i].match, remain_keta-k ) )
			return true;
	}
	return false;
}


int main(){
	cin >> n >> m;
	
	vector<int> a(m);
	rep(i,m){
		cin >> a[i];
	}
	sort(a.rbegin(),a.rend());
	
	int digit_to_match[] = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
	set<int> s;
	rep(i,m){
		int match = digit_to_match[a[i]];
		if ( s.count(match) == 0 )
			nums.push_back({a[i],match,100,0});
		s.insert(match);
	}
	m = nums.size();
	
	int min_match = 100;
	for ( int i = nums.size()-1; i >= 0; i-- ){
		nums[i].min_match = min_match;
		chmin(min_match, nums[i].match);
		eprintf( "digit,=%d match=%d min_match=%d\n", nums[i].digit, nums[i].match, nums[i].min_match );
	}
	
	for ( int keta = n / min_match; keta > 0; keta-- ){
		eprintf( "\n\nketa=%d\n", keta );
		if ( dfs( 0, n, keta ) ){
			sort(nums.begin(), nums.end(), [](numinfo &l, numinfo &r){
				return l.digit>r.digit;
			});
			rep(i,m){
				rep(j,nums[i].n){
					cout << nums[i].digit;
				}
			}
			cout << endl;
			return 0;
		}
	}
	
	return 0;
}


