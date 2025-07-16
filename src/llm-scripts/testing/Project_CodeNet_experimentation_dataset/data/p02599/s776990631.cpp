#include<stdio.h>
#include<math.h>
#include<algorithm> 
#define reg register
#define ri reg int
#define rep(i, x, y) for(ri i = x; i <= y; ++i)
#define nrep(i, x, y) for(ri i = x; i >= y; --i)
#define DEBUG 1
#define ll long long
#define max(i, j) (i) > (j) ? (i) : (j)
#define min(i, j) (i) < (j) ? (i) : (j)
struct IO {
	#define MAXSIZE (1 << 20)
	#define isdigit(x) (x >= '0' && x <= '9')
	char buf[MAXSIZE], *p1, *p2;
	char pbuf[MAXSIZE], *pp;
	#if DEBUG
	#else
		IO() : p1(buf), p2(buf), pp(pbuf) {}
		~IO() {
			fwrite(pbuf, 1, pp - pbuf, stdout);
		}
	#endif
	inline char gc() {
		#if DEBUG
    		return getchar();
		#endif
    	if(p1 == p2)
			p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
    	return p1 == p2 ? ' ' : *p1++;
	}
	inline bool blank(char ch) {
    	return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
	}
	template <class T>
	inline void read(T &x) {
    	register double tmp = 1;
    	register bool sign = 0;
    	x = 0;
    	register char ch = gc();
    	for(; !isdigit(ch); ch = gc())
    		if(ch == '-') sign = 1;
    	for(; isdigit(ch); ch = gc())
			x = x * 10 + (ch - '0');
    	if(ch == '.')
			for(ch = gc(); isdigit(ch); ch = gc())
        		tmp /= 10.0, x += tmp * (ch - '0');
    	if(sign) x = -x;
	}
	inline void read(char *s) {
		register char ch = gc();
		for(; blank(ch); ch = gc());
		for(; !blank(ch); ch = gc())
			*s++ = ch;
    	*s = 0;
	}
	inline void read(char &c) {
    	for(c = gc(); blank(c); c = gc());
	}
	inline void push(const char &c) {
		#if DEBUG
    		putchar(c);
		#else
    		if(pp - pbuf == MAXSIZE) {
				fwrite(pbuf, 1, MAXSIZE, stdout);
				pp = pbuf;
			}
    		*pp++ = c;
		#endif
	}
	template <class T>
	inline void write(T x) {
    	if(x < 0) {
			x = -x;
			push('-');
		}
    	static T sta[35];
    	T top = 0;
    	do{
			sta[top++] = x % 10;
			x /= 10;
    	}while(x);
    	while(top)
			push(sta[--top] + '0');
	}
	template <class T>
	inline void write(T x, char lastChar) {
    	write(x);
		push(lastChar);
	}
} io;
int aa[1000010], cnt[1000010], belong[1000010];
int n, m, size, bnum, now, ans[1000010];
struct query { /*询问*/
	int l, r, id;
} q[1000010];

int cmp(query a, query b) {
	return (belong[a.l] ^ belong[b.l]) ? belong[a.l] < belong[b.l] : ((belong[a.l] & 1) ? a.r < b.r : a.r > b.r); /*奇偶优化后的排序*/
}
int main() {
	io.read(n), io.read(m);
	size = sqrt(n);
	bnum = ceil((double)n / size);
	rep(i, 1, bnum) 
		rep(j, (i - 1) * size + 1, i * size) {
			belong[j] = i; /*依旧不知道所以然的离散化*/
		}
	rep(i, 1, n) io.read(aa[i]); 
	rep(i, 1, m) {
		io.read(q[i].l), io.read(q[i].r);
		q[i].id = i; /*读入每一个询问*/
	}
	std::sort(q + 1, q + m + 1, cmp);
	int l = 1, r = 0;
	rep(i, 1, m) {
		int ql = q[i].l, qr = q[i].r; /*莫队主体*/
		while(l < ql) now -= !--cnt[aa[l++]]; /*需要移动就移,在移的过程中更新答案*/
		while(l > ql) now += !cnt[aa[--l]]++;
		while(r < qr) now += !cnt[aa[++r]]++;
		while(r > qr) now -= !--cnt[aa[r--]];
		ans[q[i].id] = now;
	}
	rep(i, 1, m) io.write(ans[i], '\n');
}