#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define gcu getchar_unlocked
#define pcu putchar_unlocked
#define _il inline
#define _in _il int in
#define _sc _il bool scan
_in(int c){int n=0;bool m=false;if(c=='-')m=true,c=gcu();
	do{n=10*n+(c-'0'),c=gcu();}while(c>='0');return m?-n:n;} //&&c<='9'
_in() {return in(gcu());}
_sc(int &n){int c=gcu();return c==EOF?false:(n=in(c),true);}
_sc(char &c){c=gcu();gcu();return c!=EOF;}
//_sc(string &s){int c;s="";
//	for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=c;}}
template <typename H,typename... T> _sc(H &h, T&&... t){return scan(h)&&scan(t...);}
#define _vo _il void out
#define _vl _il void outl
template <typename T>
_vo(T n){static char buf[20];char *p=buf;
	if(n<0)pcu('-'),n*=-1;if(!n)*p++='0';else while(n)*p++=n%10+'0',n/=10;
	while (p!=buf)pcu(*--p);}
_vo(const char *s){while(*s)pcu(*s++);}
_vo(char c){pcu(c);}
//_vo(string &s){for (char c: s) pcu(c);}
template <typename H,typename... T> _vo(H&& h, T&&... t){out(h);out(move(t)...);}
//template <typename T> _vo(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);out('\n');}
_vl(){out('\n');}
template <typename... T> _vl(T&&... t){out(move(t)...);outl();}

template<int N>
struct sieve {
	bool s[N];
	constexpr sieve() : s() {
		for (int i = 0; i < N; i++)
			s[i] = true;
		for (int i = 4; i < N; i += 2)
			s[i] = false;
		for (int i = 9; i < N; i += 6)
			s[i] = false;
		for (int i = 6, e = sqrt(N); i <= e; i += 6) {
			for (int j : {i - 1, i + 1})
				if (s[j])
					for (int k = j * j; k < N; k += j)
						s[k] = false;
		}
	}
};

int main() {
	enum {N = 10001};
	constexpr sieve<N> s;
	vector<int> t = {5};
	for (int i = 7; i < N; i += 6)
		if (s.s[i - 2] && s.s[i])
			t.push_back(i);
	for (int n; (n = in());) {
		auto r = upper_bound(t.begin(), t.end(), n) - 1;
		outl(*r - 2, ' ', *r);
	}
}
