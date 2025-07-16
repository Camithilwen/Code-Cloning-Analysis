#include <iostream>
#include <cstdio>
using namespace std;
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
typedef struct{
    int head;
    int tail;
    int right;
    int left;
    int up;
    int down;
} dice;
dice s(dice a) {
    int buf;
    buf = a.tail;
    a.tail = a.down;
    a.down = a.head;
    a.head = a.up;
    a.up = buf;
	return a;
}
dice n(dice a) {
	return s(s(s(a)));
}
dice e(dice a) {
    int buf;
    buf = a.tail;
    a.tail = a.right;
    a.right = a.head;
    a.head = a.left;
    a.left = buf;
	return a;
}
dice w(dice a) {
	return e(e(e(a)));
}
dice rev(dice a) {
	return e(e(a));
}
dice round(dice a) {
	int buf;
	buf = a.right;
	a.right = a.up;
	a.up = a.left;
	a.left = a.down;
	a.down = buf;
	return a;
}
bool same(dice a, dice b) {
	dice c = a;
	rep(i,4) {
		if(c.head == b.head && c.tail == b.tail && c.up == b.up && c.down == b.down && c.right == b.right && c.left == b.left) return true;
		c = round(c);
	}
	return false;
}

int main() {
    int k, a[105][6];
	cin >> k;
	rep(i,k) {
		rep(j,6) {
	        cin >> a[i][j];
		}
	}
	rep(i,k) {
		rep2(j,i+1,k) {
			dice da, db;
			da.head = a[i][0];
			da.down = a[i][1];
			da.right = a[i][2];
			da.left = a[i][3];
			da.up = a[i][4];
			da.tail = a[i][5];
			db.head = a[i+j][0];
			db.down = a[i+j][1];
			db.right = a[i+j][2];
			db.left = a[i+j][3];
			db.up = a[i+j][4];
			db.tail = a[i+j][5];	
			if(same(da,db) || same(s(da), db) || same(n(da), db) || same(e(da), db) || same(w(da), db) || same(rev(da), db)) {
				cout << "No" <<endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;	
	return 0;
}