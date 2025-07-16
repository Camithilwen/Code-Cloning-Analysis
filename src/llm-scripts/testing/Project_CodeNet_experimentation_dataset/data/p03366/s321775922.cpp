#include <cstdio>
typedef long long ll; 
ll pos[100005], cnt[100005], ans; 
void work(int l, int r, int s)
{
	if (pos[r] < s)
		ans += s - pos[l]; 
	else if (pos[l] > s)
		ans += pos[r] - s; 
	else
	{
		ans += pos[r] - pos[l];
		if (cnt[l] >= cnt[r])
		{
			while (l < r && cnt[l] >= cnt[r])
				cnt[l] += cnt[r--]; 
		}
		else
		{
			while (l < r && cnt[l] < cnt[r])
				cnt[r] += cnt[l++]; 
		}
		work(l, r, s); 
	}
}
int main()
{
	// freopen("AGC023-D.in", "r", stdin); 
	int n, s; 
	scanf("%d%d", &n, &s); 
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", pos + i, cnt + i); 
	work(0, n - 1, s); 
	printf("%lld\n", ans);
	return 0; 
}
