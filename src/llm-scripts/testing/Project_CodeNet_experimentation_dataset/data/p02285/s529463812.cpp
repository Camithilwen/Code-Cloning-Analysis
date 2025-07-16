#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

#define NIL -1
#define N 500001

//struct Node{
//	int val;
//	Node *p, *l, *r;
//};

struct Node {
	int val;
	Node *p, *l, *r;
	Node(int v) :val(v), p(NULL), l(NULL), r(NULL){}
	Node() :val(0), p(NULL), l(NULL), r(NULL){}
};

Node T[N];
int D[N], H[N];

Node *root;

void insert(int k){
	Node *y = NULL;
	Node *x = root;
	Node *z = new Node(k);

	while (x != NULL && x->val != k){
		y = x;
		if (k > x->val) x = x->r;
		else x = x->l;
	}
	z->p = y;
	if (y == NULL) root = z;
	else{
		if (k < y->val) y->l = z;
		else y->r = z;
	}
}

Node *find(int val){
	Node *p = root;
	while (p != NULL && p->val != val) {
		if (val < p->val) p = p->l;
		else p = p->r;
	}
	return p;
}

void ino(Node *p){
	if (p == NULL) return;
	ino(p->l);
	printf(" %d", p->val);
	ino(p->r);
}

void preo(Node *p){
	if (p == NULL) return;
	printf(" %d", p->val);
	preo(p->l);
	preo(p->r);
}

Node *mi(Node *z){
	while (z->l != NULL) z = z->l;
	return z;
}

Node *suc(Node *z){
	return mi(z->r);
	//if (z->r != NULL) return mi(z->r);
	//Node *y = z->p;
	//while (y != NULL && z == y->r) {
	//	z = y;
	//	y = y->p;
	//}
	//return y;
}

void del(Node *z){
	Node *y = NULL;
	Node *x = NULL;

	if (NULL == z->l || NULL == z->r) y = z;
	else y = suc(z);

	if (NULL != y->l) x = y->l;
	else x = y->r;

	if (NULL != x) x->p = y->p;

	if (NULL == y->p) root = x;
	else {
		if (y == y->p->l) y->p->l = x;
		else y->p->r = x;
	}

	if (y != z) z->val = y->val;
	delete y;
}


int main(){
	int n; cin >> n;

	int val;
	string com;
	for (int i = 0; i < n; ++i) {
		cin >> com;
		if (com[0] == 'f'){
			cin >> val;
			Node *p = find(val);
			cout << ((p == NULL) ? "no" : "yes") << endl;
		}
		else if (com[0] == 'i'){
			cin >> val;
			insert(val);
		}
		else if (com[0] == 'p'){
			ino(root); cout << "\n";
			preo(root); cout << "\n";
		}
		else if (com[0] == 'd'){
			cin >> val;
			del(find(val));
		}
	}

	return 0;
}

//yes
//yes
//yes
//no
//no
//no
//yes
//yes
//1 2 3 7 8 22
//8 2 1 3 7 22
//1 2 8 22
//8 2 1 22