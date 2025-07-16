#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;

const int NIL = -1;
const int MAX = 2147483647;
clock_t START, END;

struct Node {
	int l, r, key, lazy;
};

bool debug = false;
Node Tree[500010];
int mark[500010];
int n = 0, N = 1;


void update(int x, int y, int z, int k, int height)
{
	if (!mark[k]) {
		Tree[k].l = k * (1 << height) - N;
		Tree[k].r = min(Tree[k].l + (1 << height) - 1, n - 1);
		mark[k] = 1;
	}
	if (x > y)
		return;
	if (x <= Tree[k].l && Tree[k].r <= y) {
		Tree[k].key = z;
		Tree[k].lazy = 1;
		return;
	}
	else if (Tree[k].r < x || Tree[k].l > y) {
		return;
	}
	else {
		if (Tree[k].lazy) {
			Tree[k].lazy = 0;
			Tree[2 * k].key = Tree[2 * k + 1].key = Tree[k].key;
			Tree[2 * k].lazy = Tree[2 * k + 1].lazy = 1;
		}
		update(x, min(Tree[k].l + (1 << (height - 1)) - 1, y), z, 2 * k, height - 1);
		update(max(Tree[k].l + (1 << (height - 1)), x), y, z, 2 * k + 1, height - 1);
	}
}

int find(int k, int height, int z)
{
	if (!mark[k]) {
		Tree[k].l = k * (1 << height) - N;
		Tree[k].r = min(Tree[k].l + (1 << height) - 1, n - 1);
		mark[k] = 1;
	}
	if (Tree[k].lazy) {
		Tree[2 * k].key = Tree[2 * k + 1].key = Tree[k].key;
		Tree[2 * k].lazy = Tree[2 * k + 1].lazy = 1;
		return Tree[k].key;
	}
	else {
		if (z <= Tree[k].l + (1 << (height - 1)) - 1)
			return find(2 * k, height - 1, z);
		else
			return find(2 * k + 1, height - 1, z);
	}
}

int main(void)
{
	if (debug) {
		START = clock();
		freopen("in15.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	}
	int q, com, x, s, t, k, height = 0;
	scanf("%d%d", &n, &q);
	while (N < n) {
		N *= 2;
		height++;
	}
	for (int i = 1; i <= n + N - 1; i++) {
		Tree[i].key = MAX;
		Tree[i].lazy = 1;
	}
	for (int i = 0; i < q; i++) {
		scanf("%d", &com);	 
		if (com) {
			scanf("%d", &k);
			printf("%d\n", find(1, height, k));
		}
		else {
			scanf("%d%d%d", &s, &t, &x);
			update(s, t, x, 1, height);
		}
	}
	if (debug) {
		END = clock();
		double endtime = (double)(END - START) / 1000;
		printf("total time = %lf s", endtime);
	}
	return 0;
}
