#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

struct ad_set
{
	int tag;
	deque<int> que;
	
	void subt(int x)
	{
		tag += x;
	}
	
	void push_front(int x)
	{
		que.push_front(x + tag);
	}
	void push_back(int x)
	{
		que.push_back(x + tag);
	}
	int back()
	{
		return que.back() - tag;
	}
	void pop_back()
	{
		que.pop_back();
	}
	int size()
	{
		return que.size();
	}
}tre;

int n;
char s[1000005], t[1000005];
int term[1000005], dest[1000005];
vector<int> occ[26];

int main()
{
	scanf("%d%s%s", &n, s, t);
	rep(i, n) {
		s[i] -= 'a';
		t[i] -= 'a';
	}
	rep(i, n) occ[s[i]].push_back(i);
	int maxt = n - 1;
	for(int i = n - 1; i >= 0; i --) {
		maxt = min(maxt, i);
		vector<int>::iterator pos = upper_bound(occ[t[i]].begin(), occ[t[i]].end(), maxt);
		if(pos == occ[t[i]].begin()) {
			printf("-1\n");
			return 0;
		}
		else maxt = term[i] = *(-- pos);
	}
	
	rep(i, n) dest[i] = -1;
	term[n] = -1;
	for(int i = n - 1; i >= 0; i --)
	if(term[i] != term[i + 1]) dest[term[i]] = i;
	
	int ans = 0;
	for(int i = n - 1; i >= 0; i --) {
		if(dest[i] == -1) continue;
		tre.subt(1);
		tre.push_front(i);
		while(tre.size() > 0 && tre.back() >= dest[i]) tre.pop_back();
		tre.push_back(dest[i]);
		ans = max(ans, tre.size());
	}
	printf("%d\n", ans - 1);
	return 0;
}