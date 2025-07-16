#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#define rep(i,n) for(auto i=0;i<(n);i++)
#define all(vs) (vs).begin(),(vs).end()
#define roundup(A,B) (A)/(B)+((A)%(B)==0?0:1)
#define read(type,name) type name;cin>>name
using namespace std;


/*
  予想と答えをすべて比較するのが最速。O(n)
*/
void A() {
	string s, t;
	cin >> s >> t;
	int answer = 0;
	rep(i, s.length()) {
		if (s[i] == t[i])answer++;
	}
	cout << answer << endl;
}

/*
  タップを使うごとにA-1ずつ増える。Bと1の距離をA-1で割った（切り上げ）のが答え。
  A,Bの値によらないのでO(1)の解法である。
*/
void B() {
	int A, B; cin >> A >> B;
	cout << roundup(B-1, A-1) << endl;
}

/*
  左から走査することで最大長を求めることができる。最大長を0で初期化し、
  左端からスタートする。右に進める限り現在の長さをincrementし、進めなくなったところで最大長を更新する。
  そして止まったところからリセットして再開する。これを繰り返すことで最大長を求めることができる。
  計算量はO(n)、空間量はO(1)となる。
*/
void C() {
	int n; cin >> n;
	int length = 0, max_length = 0;
	int prev = 0, current;
	rep(i, n) {
		cin >> current;
		if (prev >= current) {
			length++;
		} else {
			max_length = max(max_length, length);
			length = 0;
		}
		prev = current;
	}
	max_length = max(max_length, length);
	cout << max_length << endl;
}

/*
　剰余を最大にするのは、MをM+1で割った場合であるから、
 iに対して1つずれた順列を作れば最適である。配列の最後Nについては、
 N+1を用意することはできないので、1で剰余を取る（必ず10になる）。
 このやり方で和を求めた場合は、1からN-1までの和に等しいので(N-1)(N)/2となる。
 　　->これが最大っていうのはどうわかるの?
*/
void D() {
	read(int, n);
	cout << n * (n - 1) / 2 << endl;
}

/*
　総当たりで調べてO(N^2)を試してみよう
*/
struct Player {
	queue<int> versus{};
	bool available{ true };
	bool matchable(int i) {
		return available && versus.front() == i;
	}
};
void E() {
	read(int, n);
	auto ps = vector<Player>(n);
	rep(i, n) {
		rep(j, n - 1) {
			read(int, p);
			ps[i].versus.push(p - 1);
		}
	}
	int days = 0;
	int remains = n;
	while (true) {
		bool matched = false;
		rep(i, ps.size()) {
			if (!ps[i].available||ps[i].versus.empty())continue;
			auto v = ps[i].versus.front();
			if (ps[v].matchable(i)) {
				matched = true;
				ps[i].versus.pop(); ps[i].available = false; if (ps[i].versus.empty()) remains--;
				ps[v].versus.pop(); ps[v].available = false; if (ps[v].versus.empty()) remains--;
			}
		}
		for (auto& p : ps)p.available = !p.versus.empty();
		days++;
		if (remains == 0) {
			cout << days << endl;
			return;
		}
		if (!matched) {
			cout << -1 << endl;
			return;
		}
	}
}

int main() {
	E();
}

