 
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int Max_N(1000050);

int N, Temp[26], Last[Max_N][26];
char S[Max_N], T[Max_N];

void init()
{
	scanf("%d", &N);
	scanf("%s", S + 1);
	scanf("%s", T + 1);
	memset(Temp, -1, sizeof(Temp));
	for (int i = 1;i <= N;++i)
	{
		Temp[S[i] - 'a'] = i;
		for (int j = 0;j < 26;++j)
			Last[i][j] = Temp[j];
	}
}

//只考虑答案不为0的情况。考虑逆变换
//显然对于连续一串相同的字母，只要考虑第一个即可，因为后面的都可以在最后一次操作中直接达到目的
//考虑把S0变换到T的所有串从下到上写到一起，那么对于T的每个连续段的首字母，都是先向下走一格，然后每次只能向下走或向左走，直到走到S0
//每条路径经过的字母相同，并且路径之间两两不相交
//贪心地考虑，肯定是每个点先向下走，直到碰到其他路径再向左走，如此反复，直到到达目的地 
//考虑从后往前维护每个有用的T[i]的路径，记录每个点上最高的路径
//每次找到一个p满足p是最右的，在i的左边（包括i），S[p] = T[i]，并且上方没有路径
//若p = i，那么答案显然是不变的
//若p < i，那么对于所有p <= k <= i - 1，H[k] = H[k + 1] + 1 
 
#define LEFT  (segt[cur].l)
#define RIGHT (segt[cur].r)
#define MID   (segt[cur].mid)
#define MIN   (segt[cur].Min)
#define TAG   (segt[cur].Tag)
#define LCH   (cur << 1)
#define RCH   ((cur << 1) | 1)

struct node
{
	int l, r, mid, Tag, Min;
};
int dt;
node segt[Max_N << 2];

void build_tree(const int &cur, const int &l, const int &r)
{
	LEFT = l, RIGHT = r, MID = l + ((r - l) >> 1), TAG = 0, MIN = 1;
	if (l == r)
		return;
	build_tree(LCH, l, MID), build_tree(RCH, MID + 1, r);
}

inline void pushup(const int &cur)
{
	MIN = min(segt[LCH].Min, segt[RCH].Min);
}

inline void Add(const int &cur, const int &v)
{
	TAG += v, MIN += v;
}

inline void pushdown(const int &cur)
{
	if (TAG)
		Add(LCH, TAG), Add(RCH, TAG), TAG = 0;
}

void insert(const int &cur, const int &l, const int &r, const int &v)
{
	if (LEFT == l && RIGHT == r)
	{
		Add(cur, v);
		return;
	}
	pushdown(cur);
	if (r <= MID)
		insert(LCH, l, r, v);
	else
		if (l > MID)
			insert(RCH, l, r, v);
		else
			insert(LCH, l, MID, v), insert(RCH, MID + 1, r, v);
	pushup(cur);
}

int query(const int &cur, const int &pos)
{
	if (LEFT == RIGHT)
		return MIN;
	pushdown(cur);
	if (pos <= MID)
		return query(LCH, pos);
	else
		return query(RCH, pos);
}

int query(const int &cur, const int &l, const int &r)
{
	if (MIN > 1)
		return -1;
	if (LEFT == l && RIGHT == r)
		if (LEFT == RIGHT)
			return LEFT;
		else
		{
			pushdown(cur);
			if (segt[RCH].Min <= 1)
				return query(RCH, MID + 1, r);
			else
				return query(LCH, l, MID);
		}
	pushdown(cur);
	if (r <= MID)
		return query(LCH, l, r);
	else
		if (l > MID)
			return query(RCH, l, r);
		else
		{
			int v = query(RCH, MID + 1, r);
			if (v == -1)
				return query(LCH, l, MID);
			else
				return v;
		}
}

bool check()
{
	for (int i = 1;i <= N;++i)
		if (S[i] != T[i])
			return false;
	return true;
}

void work()
{
	build_tree(1, 1, N);
	int Ans(1);
	for (int i = N, p, h;i >= 1;--i)
		if (i == 1 || T[i] != T[i - 1])
		{
			if ((p = query(1, 1 + dt, i + dt)) == -1)
			{
				printf("-1");
				return;
			}
			p -= dt;
			if ((p = Last[p][T[i] - 'a']) == -1)
			{
				printf("-1");
				return;
			}
			h = query(1, i + dt);
			if (p <= i - 1)
				Ans = max(Ans, h + 1), ++dt, insert(1, p + dt, (i - 1) + dt, +1);
		}
	printf("%d", Ans);
}

int main()
{
	init();
	if (check())
		printf("0");
	else
		work();
	return 0;
}