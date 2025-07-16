#include <iostream>
#include <time.h>
#include <algorithm>
#include <stdio.h>
#include<string.h>

typedef long long LL;

using namespace std;

const int times = 20;
LL fac[1001];
int cnt;

LL mul(LL a, LL b, LL mod)
{
	LL ans = 0;
	while (b)
	{
		if (b & 1)
		{
			ans = (ans + a) % mod;
		}
		a = (a << 1) % mod;
		b >>= 1;
	}
	return ans;
}

LL pow(LL a, LL b, LL mod)
{
	LL ans = 1;
	while (b)
	{
		if (b & 1)
		{
			ans = mul(ans, a, mod);
		}
		b >>= 1;
		a = mul(a, a, mod);
	}
	return ans;
}

bool witness(LL a, LL n)
{
	LL temp = n - 1;
	int j = 0;
	while (temp % 2 == 0)
	{ // 其实就是得到 m
		j++;
		temp /= 2;
	}
	LL x = pow(a, temp, n);
	if (x == 1 || x == n - 1)
	{ // 判断a^m
		return true;
	}
	while (j--)
	{
		x = mul(x, x, n); // 进一步判断 a^(2m)  a^(4m) ...
		if (x == n - 1)
			return true;
	}
	return false;
}

bool miller_rabin(LL n)
{
	if (n == 2)
	{ //  如果是2肯定是素数
		return true;
	}
	if (n < 2 || n % 2 == 0)
	{ //如果小于2或者是大于2的偶数肯定不是素数
		return false;
	}
	for (int i = 0; i < times; i++)
	{ //随机化检验
		LL a = rand() % (n - 1) + 1;
		if (!witness(a, n))
			return false;
	}
	return true;
}

LL gcd(LL a, LL b)
{ // 这里的gcd和一般的gcd不一样
	if (a == 0)
	{ // pollard_rho的需要
		return 1;
	}
	if (a < 0)
	{ // 可能有负数
		return gcd(-a, b);
	}
	while (b)
	{
		LL t = a % b;
		a = b;
		b = t;
	}
	return a;
}

LL pollard_rho(LL n, LL c)
{                    // 找因子
	LL i = 1, k = 2; // 用来判断是否成环
	LL xx = rand() % n, y = xx;
	while (1)
	{
		i++;
		xx = (mul(xx, xx, n) + c) % n;
		LL d = gcd(y - xx, n);
		if (1 < d && d < n)
		{ // 找到一个因数
			return d;
		}
		if (y == xx)
		{ // 出现循环，那么查找失败
			return n;
		}
		if (i == k)
		{ // 相当一个优化？
			y = xx;
			k <<= 1;
		}
	}
}

void find(LL n)
{ // 通过因数来找质因子
	if (miller_rabin(n))
	{
		fac[cnt++] = n; // 记录质因子
		return;
	}
	LL p = n;
	while (p >= n)
		p = pollard_rho(p, rand() % (n - 1) + 1); //如果转了一圈还是p那么继续
	find(p);
	find(n / p);
}

int main()
{
	srand(251);
	LL a, b;
	cin>>a>>b;
    if(a==1||b==1){
        cout<<1;
        return 0;
    }
	if (miller_rabin(a))
	{
		if (b % a == 0)
			cout << 2;
		else
			cout << 1;
		return 0;
	}
	if (miller_rabin(b))
	{
		if (a % b)
			cout << 2;
		else
			cout << 1;
		return 0;
	}
	cnt = 0;
	find(a);
	LL fa[1001];
	memcpy(fa, fac, sizeof(fac));
	sort(fa, fa + cnt);
	int ss = cnt;
	cnt = 0;
	find(b);
	sort(fac, fac + cnt);
	int ans = 0;
	for (int i = 0; i < ss; i++) {
		if (i && fa[i] == fa[i - 1])continue;
		for (int j = 0; j < cnt; j++) {
			if (j && fac[j] == fac[j - 1])continue;
			if (fac[j] == fa[i])ans++;
		}
	}
	cout << ans+1;
	return 0;
}