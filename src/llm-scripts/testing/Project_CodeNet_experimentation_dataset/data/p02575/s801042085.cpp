#include<bits/stdc++.h>
#define SORT(v) sort(v.rbegin() , v.rend())
#define si(n) scanf( "%d" , &n)
#define sii(n , m) scanf( "%d %d" , &n , &m)
#define sl(n) scanf( "%lld" , &n)
#define sll(n , m) scanf( "%lld %lld" , &n, &m)
#define ss(cad) scanf( "%s" , cad)
#define sz(x) (int)x.size()
#define PB push_back
#define fst first
#define scn second
#define DBG(x) cerr << #x << " = " << (x) << endl
#define M 1000000007
#define N_MAX 1000010
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vp;

void mostrar(set<pi> ls){
	for(auto x: ls)
		printf("(%d, %d) ", x.fst, x.scn);
}

int main(){
	int h, w;
	sii(h, w);
	set<pi> lista;
	multiset<int> num;
	for(int i = 1; i <= w; i++){
		lista.insert({i, 1});
		num.insert(1);
	}
	int cnt = 0;
	while(h--){
		int a, b;
		sii(a, b);
		bool sw = 0;
		auto pt = lista.lower_bound(pi(a, -1));
		auto pt2 = pt;
		pi mitad = {-1, -1};
		pi inicio;
		if(pt != lista.begin()){
			sw = 1;
			pt--;
			mitad = *pt;
			inicio = *pt;
			pt++;
		}
		while(pt != lista.end() && pt->fst <= b){
			pt2 = pt;
			mitad = *pt;
			num.erase(num.lower_bound(mitad.scn));
			pt++;
			lista.erase(pt2);
		}
		pt2 = lista.lower_bound(pi(b+1, -1));
		if(mitad.fst != -1 && b != w){
			if(pt2 != lista.end() && pt2->fst != b+1){
				int val = mitad.scn + b-mitad.fst+1;
				//update(val, 1);
				num.insert(val);
				lista.insert({b+1, val});
			}
			else if(pt2 == lista.end()){
				int val = mitad.scn + b-mitad.fst+1;
				//update(val, 1);
				num.insert(val);
				lista.insert({b+1, val});
			}
		}
		if(sw){
			int val = inicio.scn + a-inicio.fst;
			//update(val, 1);
			num.insert(val);
			lista.insert({a, val});
		}
		if(num.empty())
			printf("-1\n");
		else
			printf("%d\n", *num.begin()+cnt);
		//mostrar(lista);
		//cout << endl;
		cnt++;
	}
    return 0;
}