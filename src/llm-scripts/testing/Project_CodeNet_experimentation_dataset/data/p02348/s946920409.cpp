#include <bits/stdc++.h>
using namespace std;

int arr[100005 << 2], value[100005], n, q;

void updata(int a, int b, int x, int k = 0, int l = 0, int r = (1 << 17)){
	if (b <= l || r <= a)return;
	if (a <= l && r <= b){
		arr[k] = max(arr[k], x);
		return;
	}
	int m = (l + r) / 2;
	updata(a, b, x, k * 2 + 1, l, m);
	updata(a, b, x, k * 2 + 2, m, r);
}

int query(int x){
	x += (1 << 17) - 1;
	int res = arr[x];
	while (x){
		x = (x - 1) / 2;
		res = max(res, arr[x]);
	}
	return res;
}

int main()
{
	value[0] = 2147483647;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; ++i){
		int ch, a, b;
		scanf("%d", &ch);
		if (ch){
			scanf("%d", &a);
			printf("%d\n", value[query(a)]);
		}else{
			scanf("%d%d%d", &a, &b, &value[i]);
			++b;
			updata(a, b, i);
		}
	}
	return 0;
}
