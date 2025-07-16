#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100 + 10;

int total, N;
int a[MAXN]= {0};
int st[MAXN]= {0}, ed[MAXN]= {0};
int odd[MAXN]= {0}, ocnt = 0;

int ans[MAXN]= {0}, acnt = 0;

int getnum () {
	int num = 0;
	char ch = getchar ();

	while (! isdigit (ch))
		ch = getchar ();
	while (isdigit (ch))
		num = (num << 3) + (num << 1) + ch - '0', ch = getchar ();

	return num;
}

int main () {
	total = getnum (), N = getnum ();
	for (int i = 1; i <= N; i ++) {
		a[i] = getnum ();
		if (a[i] & 1) odd[++ ocnt] = i;
	}
	if (N == 1) {
		printf ("%d\n", a[1]);
		if (total == 1) puts ("1"), puts ("1");
		else {
			puts ("2");
			printf ("1 %d\n", total - 1);
		}
		return 0;
	}
	if (ocnt > 2) {
		puts ("Impossible");
		return 0;
	}
	if (ocnt >= 1) swap (a[1], a[odd[1]]);
	if (ocnt >= 2) swap (a[N], a[odd[2]]);
	ans[++ acnt] = a[1] + 1;
	for (int i = 2; i < N; i ++) ans[++ acnt] = a[i];
	if (a[N] - 1 > 0) ans[++ acnt] = a[N] - 1;
	for (int i = 1; i <= N; i ++) {
		if (i > 1) putchar (' ');
		printf ("%d", a[i]);
	}
	printf ("\n%d\n", acnt);
	for (int i = 1; i <= acnt; i ++) {
		if (i > 1) putchar (' ');
		printf ("%d", ans[i]);
	}
	puts ("");

	return 0;
}

/*
3 2
2 1
*/

/*
6 1
6
*/

/*
55 10
1 2 3 4 5 6 7 8 9 10
*/