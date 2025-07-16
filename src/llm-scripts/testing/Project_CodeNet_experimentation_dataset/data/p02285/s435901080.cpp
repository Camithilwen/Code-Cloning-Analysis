#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node { 
    int key;
    node *left, *right, *parent;
};
node *root, *NIL;

node* minimum(node *x) {
    while( x ->left != NIL ) x = x->left;
    return x;
}

node * successor( node *x ) {
    if( x->right != NIL ) return minimum(x->right);
    node *y = x->parent;
    while( y != NIL && x == y->right ) {
        x = y;
        y = y->parent;
    }
    return y;
}

void delete_node( node* z ) {
    node *y, *x;

    if( z->left == NIL || z->right == NIL ) y = z;
    else y = successor(z);
    if( y ->left != NIL ) x = y->left;
    else x = y->right;

    if( x != NIL ) x->parent = y ->parent;

    if( y->parent == NIL ) root = x;
    else
        if(y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }
    
    if( y != z ) z->key = y->key;
}

void insert(int k) {
    node *y = NIL;
    node *x = root;
    node *z;

    z = (node *)malloc(sizeof(node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while( x != NIL ) {
        y = x;
        if( z->key < x->key ) x = x->left;
        else x = x->right;
    }
    z->parent = y;
    if( y == NIL ) root = z;
    else {
        if( z->key < y->key ) y->left = z;
        else y ->right = z;
    }
}

node* find(node *x, int key) {
    while( x != NIL && key != x->key) {
        if( key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}

void preParse(node* u) {
    if(u == NIL) return;
    printf(" %d", u->key);
    preParse(u->left);
    preParse(u->right);
}

void inParse(node* u) {
    if(u == NIL) return;
    inParse(u->left);
    printf(" %d", u->key);
    inParse(u->right);
}

signed main() {
    ll n; scanf("%lld", &n); 
    string com;
    for( ll i = 0; i < n; i++ ) {
        cin >> com;
        if( com.at(0) == 'i') {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if( com.at(0) == 'f' ) {
            int x;
            scanf("%d", &x);
            node* t = find(root, x);
            if( t != NIL ) printf("yes\n");
            else printf("no\n");
        } else if( com.at(0) == 'd' ) {
            int x; scanf("%d", &x);
            delete_node(find(root, x));
        } else  {
            inParse(root);
            putchar('\n');
            preParse(root);
            putchar('\n');
        }
    }

    return 0;
}



