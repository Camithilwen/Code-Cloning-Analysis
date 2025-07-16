//#define MYDEBUG
#include <bits/stdc++.h>

#ifdef MYDEBUG
#define dbp(x) cout<<#x<<": "<<x<<endl
#define dbp2(x,y) cout<<#x<<","<<#y<<": "<<x<<","<<y<<endl
#define dbp3(x,y,z) cout<<#x<<","<<#y<<","<<#z<<": "<<x<<","<<y<<","<<z<<endl
#define dbp4(w,x,y,z) cout<<#w<<","<<#x<<","<<#y<<","<<#z<<": "<<w<<","<<x<<","<<y<<","<<z<<endl
#define ifcin(x) std::ifstream cin(x)
#else
#define dbp(x)
#define dbp2(x,y)
#define dbp3(x,y,z)
#define dbp4(w,x,y,z)
#define ifcin(x)
#endif
#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for(int i=from; i<to; ++i)
#define REP(i, from, to) for(int i=from; i<=to; ++i)
#define EPS = 1e-14;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::max;
using std::min;
using std::swap;
using std::string;
using std::fill;
using std::pair;
using std::sort;
using std::reverse;
using std::pair;
using std::greater;
using std::priority_queue;
using std::ostream;
typedef std::complex<int> P;

template<typename T>
ostream& operator<<(ostream& out, const vector<vector<T> >& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		out << v[i] << endl;
	}
	return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
	out << "[";
	size_t last = v.size() - 1;
	for (size_t i = 0; i < v.size(); ++i) {
		out << v[i];
		if (i != last) {
			out << ",";
		}
	}
	out << "]";
	return out;
}

const int MAX_N = 1 << 17;
const int LAZY_INIT = -1;
const int VAL_INIT = INT_MAX;
int N = 1;
int mini[MAX_N*2], lazy[MAX_N*2];

void init(int n_){
	while(N < n_){
		N *= 2;
	}
	for(int i = 0; i < N*2 - 1; ++i){
		lazy[i] = LAZY_INIT;
		mini[i] = VAL_INIT;
	}
}

void setLazy(int k, int v){
	lazy[k] = v;
	mini[k] = v;
}

void push(int k){
	if(lazy[k] == LAZY_INIT){
		return;
	}
	setLazy(k*2+1, lazy[k]);
	setLazy(k*2+2, lazy[k]);
	lazy[k] = LAZY_INIT;
}

void fix(int k){
	mini[k] = min(mini[k*2+1], mini[k*2+2]);
}

void fill(int qL, int qR, int val, int k=0, int nL=0, int nR=N){
	if(nR<=qL || qR<=nL){
		return;
	}
	if(qL<=nL && nR<=qR){
		setLazy(k, val);
		return;
	}
	push(k);
	int nM = (nL+nR)/2;
	fill(qL, qR, val, k*2+1, nL, nM);
	fill(qL, qR, val, k*2+2, nM, nR);
	fix(k);
}

int minimum(int qL, int qR, int k=0, int nL=0, int nR=N){
	if(qR<=nL || nR <=qL){
		return VAL_INIT;
	}
	if(qL<=nL && nR<=qR){
		return mini[k];
	}
	push(k);
	int nM = (nL+nR)/2;
	int vl = minimum(qL, qR, k*2+1, nL, nM);
	int vr = minimum(qL, qR, k*2+2, nM, nR);
	return min(vl, vr);
}

void print(){
	cout << "mini: ";
	rep(i, 0, N-1+N){
		cout << mini[i] << ",";
	}
	cout << endl;
	cout << "lazy: ";
	rep(i, 0, N-1+N){
		cout << lazy[i] << ",";
	}
	cout << endl;
}

int n, q;
void solve() {
	ifcin("/storage/emulated/0/AppProjects/AtCoder/jni/in.txt");
	cin >> n >> q;
	init(n);
	rep(query_index, 0, q){
		int com;
		cin >> com;
		if(com==0){
			int s,t,x;
			cin >> s >> t >> x;
			//print();
			fill(s, t+1, x);
			//dbp4(N, s,t,x);
			//print();
			//cout << endl;
		}else{
			int i;
			cin >> i;
			cout << minimum(i, i+1) << endl;
		}
	}
}

int main() {
	solve();
}