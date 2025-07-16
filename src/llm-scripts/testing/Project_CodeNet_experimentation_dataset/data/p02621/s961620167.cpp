#include <bits/stdc++.h>
#define ms(a) memset (a , 0 , sizeof a)
#define rr(i, a, b) for(register int i=a;i<=b;++i)
#define re(i, a, b) for(register int i=a;i>=b;--i)
#define reps(s) for(register int i=head[s];i;i=Next[i])
typedef long long ll ;

#define v(int) vector <int> 
#define pb push_back
#define pp push
#define fi first
#define se second
using namespace std ;

const int N = 100 ;
int qwq () {
	char ch = getchar () ;
	int x = 0 , f = 1 ;
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1 ; ch = getchar() ;}
	while (ch >= '0' && ch <= '9') {x = x *10 + ch - '0' ; ch = getchar() ;}
	return x * f ;
}
#define q qwq () 

int main () {
	int a ;
	cin >> a ;
	cout << (ll)(a + a * a + a * a * a) << endl; 
	
	return 0 ; 
}
