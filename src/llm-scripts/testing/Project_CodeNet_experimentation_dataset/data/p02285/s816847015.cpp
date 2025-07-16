# include "bits/stdc++.h"
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
typedef pair<LL, LL> pii;
const int vy[] = { -1, -1, -1, 0, 1, 1, 1, 0 }, vx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
const char dir[4] = { 'u','l','d','r' };
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
LL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b); };
LL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        sort(ALL((wpwpw)));(wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)
# define INIT                 std::ios::sync_with_stdio(false);std::cin.tie(0)
# pragma warning(disable:4996)

class node {
public:
	int key;
	node *parent, *lch, *rch;
};

node *NIL, *root;

void insert(int v) {
	node *y = NIL, *x = root, *z = new node;
	z->key = v; z->lch = z->rch = NIL;
	while (x != NIL) {
		y = x;
		if (z->key < x->key)x = x->lch;
		else x = x->rch;
	}
	z->parent = y;
	if (y == NIL)root = z;
	else if (z->key < y->key)y->lch = z;
	else y->rch = z;
	return;
}

node* find(int k) {
	node *x = root;
	while (x != NIL&&k != x->key) {
		if (k < x->key)x = x->lch;
		else x = x->rch;
	}
	return x;
}

node* next(node *z) {
	node *x, *y;
	if (z->rch != NIL) {
		x = z->rch;
		while (x->lch != NIL)x = x->lch;
		return x;
	}

	y = z->parent;
	while (y != NIL&&x == y->rch) {
		x = y;
		y = y->parent;
	}
	return y;
}

void remove(node *z) {
	node *y, *x;
	if (z->lch == NIL || z->rch == NIL)y = z;
	else y = next(z);

	if (y->lch != NIL)x = y->lch;
	else x = y->rch;

	if (x != NIL)x->parent = y->parent;

	if (y->parent == NIL)root = x;
	else if (y == y->parent->lch)y->parent->lch = x;
	else y->parent->rch = x;

	if (y != z)z->key = y->key;
	delete(y);
	return;
}

void ino(node *u) {
	if (u == NIL)return;
	ino(u->lch);
	cout << " " << u->key;
	ino(u->rch);
	return;
}

void preo(node *u) {
	if (u == NIL)return;
	cout << " " << u->key;
	preo(u->lch);
	preo(u->rch);
	return;
}

void print() {
	ino(root);
	cout << endl;
	preo(root);
	cout << endl;
	return;
}

int main() {
	int n; cin >> n;
	string s; node *a;
	while (cin >> s) {
		if (s == "insert") {
			cin >> n;
			insert(n);
		}
		else if (s == "find") {
			cin >> n;
			a = find(n);
			if (a != NIL)cout << "yes" << endl;
			else cout << "no" << endl;
		}
		else if (s == "delete") {
			cin >> n;
			remove(find(n));
		}
		else if (s == "print")print();
	}
	return 0;
}
