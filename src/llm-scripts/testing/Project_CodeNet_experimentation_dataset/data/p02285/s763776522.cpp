#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

struct node{
	int data;
	node *l, *r;
};

node *new_node(int in){
	node *ret = new node;
	ret->data = in;
	ret->l = NULL;
	ret->r = NULL;
	return ret;
}

void insert_node(node **root, int in){
	node *add = new_node(in);
	if(*root == NULL){
		*root = add;
		return ;
	}
	node *p = *root, *pp = NULL;
	while(p != NULL){
		pp = p;
		if(add->data < p->data) p = p->l;
		else p = p->r;
	}
	if(add->data < pp->data) pp->l = add;
	else pp->r = add;
	return ;
}

void print_n(node *root, bool mode){
	if(mode == true) cout << " " << root->data;
	if(root->l != NULL) print_n(root->l, mode);
	if(mode == false) cout << " " << root->data;
	if(root->r != NULL) print_n(root->r, mode);
}

void print_node(node *root){
	print_n(root, false);
	cout << endl;
	print_n(root, true);
	cout << endl;
}

void find_node(node *root, int in){
	bool ans = false;
	while(root != NULL){
		if(in == root->data){
			ans = true;
			break;
		}else if(in < root->data){
			root = root->l;
		}else{
			root = root->r;
		}
	}
	if(ans == false) cout << "no" << endl;
	else cout << "yes" << endl;
}

void delete_node(node **root, int in){
	node *p = *root, *pp = NULL;
	while(p != NULL){
		if(p->data == in) break;
		pp = p;
		if(in < p->data) p = p->l;
		else p = p->r;
	}
	if(p->l == NULL && p->r == NULL){
		if(in < pp->data) pp->l = NULL;
		else pp->r = NULL;
		delete p;
		return ;
	}
	if(p->l == NULL){
		if(in < pp->data) pp->l = p->r;
		else pp->r = p->r;
		delete p;
		return;
	}
	if(p->r == NULL){
		if(in < pp->data) pp->l = p->l;
		else pp->r = p->l;
		delete p;
		return;
	}
	node *rl = p->r, *prl = p;
	while(rl->l != NULL){
		prl = rl;
		rl = rl->l;
	}
	if(in < pp->data) pp->l = rl;
	else pp->r = rl;
	if(prl != p)prl->l = rl->r;
	else prl->r = rl->r;
	rl->l = p->l;
	rl->r = p->r;
	delete p;
}

int main(){
	int n;
	cin >> n;
	node *root = NULL;
	rep(i, n){
		string s;
		cin >> s;
		if(s == "print"){
			print_node(root);
		}else if(s == "find"){
			int in;
			cin >> in;
			find_node(root, in);
		}else if(s == "delete"){
			int in;
			cin >> in;
			delete_node(&root, in);
		}else{
			int in;
			cin >> in;
			insert_node(&root, in);
		}
	}
	return 0;
}
