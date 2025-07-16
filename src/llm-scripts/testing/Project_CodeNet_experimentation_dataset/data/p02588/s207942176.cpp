#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for(int i=(a);i<(n);++i)
#define per(i, a, n) for(int i=(a);i>(n);--i)
#define pb emplace_back
#define mp make_pair
#define lowbit(x) (x & -x)

typedef long long LL;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double EPS = 1e-8;
const double PI = acos(-1.0);

const int M = 45;
const int N = 2e5 + 10;
int n;
char s[100];

void decode(int &c2, int &c5, int &m){
	int len = strlen(s);
	LL a, b;
	bool flag = 0;
	rep(i, 0, len){
		if(s[i] == '.'){
			sscanf(s, "%lld.%lld", &a, &b);
			flag = 1;
			m = len - i - 1;
			break;
		}
	}
	if(!flag){
		sscanf(s, "%lld", &a);
		b = 0;
		m = 0;
	}

	rep(i, 0, m)	a = a * 10;
	a = a + b;

	c2=0, c5=0;

	while(a % 2 == 0){
		a >>= 1;
		++c2;
	}
	while(a % 5 == 0){
		a /= 5;
		++c5;
	}

	int c = min(c2, c5);
	m -= c;
	c2 -= c;
	c5 -= c;
}

unordered_map<int, int> MP0, O, MP2[M], MP5[M];

int main(){
	scanf("%d", &n);

	int c2, c5, lft;

	LL ans = 0, ans1 = 0;

	rep(i, 0, n){
		scanf("%s", s);
		decode(c2, c5, lft);
		
		if(c2 > 0){
			MP2[c2][lft]++;
			O[lft]++;
		} else if(c5 > 0){
			MP5[c5][lft]++;
			O[lft]++;
		} else {
			MP0[lft]++;
		}
		if(lft <= 0)	ans1--;
	}

	for(auto it : MP0){
		for(auto it1 : MP0){
			if(it.first + it1.first <= 0)	ans1 += 1LL * it.second * it1.second;
		}
	}
	
	for(auto it : MP0){
		for(auto it1 : O){
			if(it.first + it1.first <= 0)	ans += 1LL * it.second * it1.second;
		}
	}

	rep(i, 0, M){
		for(auto it : MP2[i]){
			rep(j, 0, M){
				for(auto it1 : MP2[j]){
					if(it.first + it1.first <= 0){
						ans1 += 1LL * it.second * it1.second;
					}
				}
				for(auto it1 : MP5[j]){
					if(it.first + it1.first - min(i, j) <= 0){
						ans += 1LL * it.second * it1.second;
					}
				}
			}
		}

		for(auto it : MP5[i]){
			rep(j, 0, M){
				for(auto it1 : MP5[j]){
					if(it.first + it1.first<= 0){
						ans1 += 1LL * it.second * it1.second;
					}
				}
			}
		}
	}


	printf("%lld\n", ans + ans1 / 2);

	return 0;
}
