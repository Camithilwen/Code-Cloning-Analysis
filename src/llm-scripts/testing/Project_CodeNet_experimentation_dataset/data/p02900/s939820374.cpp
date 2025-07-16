#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
#include<queue>
#include<tuple>
#include<utility>
#include<map>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define range(a) a.begin(), a.end()
#define endl "\n"
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
#define MP make_pair
using Graph = vector<vector<int>>;
const unsigned long long mod = 1e9 + 7;
const long long INF = 1LL<<60;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

template<typename T>
T gcd(T a, T b){
	if (a%b == 0)		return(b);
   else	return(gcd(b, a%b));
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll A, B;
	cin >> A >> B;
	ll upper = gcd<ll>(A, B);
	vector<ll>	D = divisor(upper);
	vector<ll>	J;
 
	FOR(i, 0, D.size() - 1)
	{
		if (binary_search(range(J), D.at(i)))
			continue;
		FOR(j, i + 1, D.size())
		{
			if (binary_search(range(J), D.at(j)))
				continue;
			if (gcd<ll>(D.at(i), D.at(j)) != 1)
			{
				J.push_back(D.at(j));
				sort(range(J));
			}
		}
	}
 
	cout << D.size() - J.size() << endl;
 
	return 0;
}

