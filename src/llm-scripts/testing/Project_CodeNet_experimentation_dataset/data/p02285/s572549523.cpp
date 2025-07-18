#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class node {
public:
	int parent,children[2],sib,val;
	node() {
		parent = -1;
		children[0] = -1;
		children[1] = -1;
		sib = -1;
		val = -1;
	}
	int deg() {
		int c = 0;
		for(int i=0;i<2;i++)if(children[i]!=-1)c++;
		return c;
	}
	string typ() {
		if(parent == -1)return "root";
		else if(deg() == 0)return "leaf";
		else return "internal node";
	}
	int get1() {
		if(children[0] == -1) return children[1];
		return children[0];
	}
};

int n = 0,c = 0;
node d[600000];

void pre(int i) {
	cout << " " << d[i].val;
	if(d[i].children[0] != -1) pre(d[i].children[0]);
	if(d[i].children[1] != -1) pre(d[i].children[1]);
}

void ino(int i) {
	if(d[i].children[0] != -1)ino(d[i].children[0]);
	cout << " " << d[i].val;
	if(d[i].children[1] != -1)ino(d[i].children[1]);
}

void pos(int i) {
	if(d[i].children[0] != -1)pos(d[i].children[0]);
	if(d[i].children[1] != -1)pos(d[i].children[1]);
	cout << " " << d[i].val;
}

void ins(int v) {
	d[c].val = v;
	if(c == 0){c++;return;}
	int h = 0;
	while(1) {
		int g;
		if(d[h].val < v) {
			g = d[h].children[1];
			if(g == -1) {
				d[c].parent = h;
				d[h].children[1] = c;
				break;
			} else {
				h = g;
			}
		} else {
			g = d[h].children[0];
			if(g == -1) {
				d[c].parent = h;
				d[h].children[0] = c;
				break;
			} else {
				h = g;
			}
		}
	}
	c++;
}

void find(int v) {
	int h = 0;
	while(1) {
		int g;
		if(h == -1) {
			cout << "no" << endl;
			return;
		}
		if(d[h].val < v) {
			h = d[h].children[1];
		} else if (d[h].val > v){
			h = d[h].children[0];
		} else {
			cout << "yes" << endl;
			return;
		}
	}
}

void del(int v) {
	int h = 0;
	while(1) {
		int g;
		if(h == -1) {
			return;
		}
		if(d[h].val < v) {
			h = d[h].children[1];
		} else if (d[h].val > v){
			h = d[h].children[0];
		} else {
			int p = d[h].parent;
			if(d[h].deg() == 0) {
				if(d[p].val < v){
					d[p].children[1] = -1;
				}
				else {
					d[p].children[0] = -1;
				}
			}
			if(d[h].deg() == 1) {
				if(d[p].val < v){
					d[p].children[1] = d[h].get1();
					d[d[h].get1()].parent = p;
				}
				else {
					d[p].children[0] = d[h].get1();
					d[d[h].get1()].parent = p;
				}
			}
			if(d[h].deg() == 2) {
				int z = d[h].children[1];
				while(1){
					if(d[z].children[0] != -1) z = d[z].children[0];
					else break;
				}
				int vv = d[z].val;
				int pp = d[z].parent;
				if(d[z].deg() == 0) {
					if(d[pp].val < vv){
						d[pp].children[1] = -1;
					}
					else {
						d[pp].children[0] = -1;
					}
				}
				if(d[h].deg() == 1) {
					if(d[pp].val < vv){
						d[pp].children[1] = d[z].get1();
						d[d[z].get1()].parent = pp;
					}
					else {
						d[pp].children[0] = d[z].get1();
						d[d[z].get1()].parent = pp;
					}
				}
				d[h].val = d[z].val;
			}

			return;
		}
	}
}

int main(void) {
	cin >> n;
	string s;
	int t;
	for(int i = 0;i < n;i++) {
		cin >> s;
		if(s == "insert") {cin >> t;ins(t);}
		else if(s == "find"){cin >> t;find(t);}
		else if(s == "delete"){cin >> t;del(t);}
		else {ino(0);cout << endl;pre(0);cout << endl;}
	}
}

