#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

struct Node{
    int key;
    Node *parent, *left, *right;
};

Node *root, *NIL;

void insert(int k){
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while(x != NIL){
        y = x;
        if(z->key < x->key) x = x->left;
        else x = x->right;
    }

    z->parent = y;

    if(y == NIL){
        root = z;
    }else{
        if(z->key < y->key) y->left = z;
        else y-> right = z;
    }

}

Node* treeMinimum(Node *x){
    while(x->left != NIL){
        x = x->left;
    }
    return x;
}

Node* find(int k){
    Node *x = root;
    while(x != NIL && x->key != k){
        if(k < x->key) x = x->left;
        else x = x->right;
    }
    return x;
}

Node* treeSuccessor(Node *x){
    if(x->right != NIL) return treeMinimum(x->right);
    Node *y = x->parent;
    while(y != NIL && x == y->right){
        x = y;
        y = y->parent;
    }
    return y;
}

void deleteNode(Node *z){
    Node *y; //削除する対象
    Node *x; //yの子

    //削除する接点を決める
    if(z->left == NIL || z->right == NIL) y = z;
    else y = treeSuccessor(z);

    //yの子xを決める
    if(y->left != NIL){
        x = y->left;
    }else{
        x = y->right;
    }
    
    if(x != NIL){
        x->parent = y->parent;
    }

    if(y->parent == NIL){
        root = x;
    }else{
        if(y == y->parent->left){
            y->parent->left = x;
        }else{
            y->parent->right = x;
        }
    }

    if(y != z){
        z->key = y->key;
    }

    free(y);

}

void inorder(Node *u){
    if(u == NIL) return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void preorder(Node *u){
    if(u == NIL) return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

void print(Node *u){
    inorder(u);
    printf("\n");
    preorder(u);
    printf("\n");
}

int main(){
    int m;
    cin >> m;
    char com[10];
    int k;

    rep(i,m){
        scanf("%s", com);
        if(com[0] == 'i'){
            scanf("%d", &k);
            insert(k);
        }else if(com[0] == 'f'){
            scanf("%d", &k);
            Node *x = find(k);
            if(x == NIL) cout << "no" << endl;
            else cout << "yes" << endl;
        }else if(com[0] == 'd'){
            scanf("%d", &k);
            Node *x = find(k);
            if(x != NIL){
                deleteNode(x);
            }
        }else{
            print(root);
        }
    }

    return 0;
}

