#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

#define int long long
#define MOD7 1000000007
#define MOD9 1000000009

#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = (a); i <= (n); i++)
#define all(a) (a).begin(), (a).end()

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int nextInt() {int a; cin >> a; return a;}
char nextChar() {char a; cin >> a; return a;}
double nextDouble() {double a; cin >> a; return a;}
string nextString() {string a; cin >> a; return a;}

void inputVector(vector<int> &v, int &n) {rep(i,n){v.push_back(nextInt());}}
void inputVector(vector<double> &v, int &n) {rep(i,n){v.push_back(nextDouble());}}
void inputVector(vector<string> &v, int &n) {rep(i,n){v.push_back(nextString());}}

class Fruit {
public:
    int time;
    int gain;
    string name;
    Fruit(string name) {
	time = 0;
	gain = 0;
	this->name = name;
    }
    bool operator< (const Fruit &a) const {
	if (gain * a.time == a.gain * time) return name < a.name;
	return gain * a.time > a.gain * time;
    }
};

signed main() {
    int N;

    while (cin >> N) {
	if (!N) break;

	vector<Fruit> fruits;
	rep(i, N) {
	    string L;
	    int P, A, B, C, D, E, F, S, M;
	    cin >> L >> P >> A >> B >> C >> D >> E >> F >> S >> M;

	    Fruit fruit = Fruit(L);
	    fruit.time = A + B + C;
	    fruit.time += (D + E) * M;
	    fruit.gain = S * F * M - P;
	    fruits.push_back(fruit);
	}
	sort(all(fruits));
	rep(i, N) {
	    cout << fruits[i].name << endl;
	}
	cout << "#" << endl;
    }


    return 0;
}