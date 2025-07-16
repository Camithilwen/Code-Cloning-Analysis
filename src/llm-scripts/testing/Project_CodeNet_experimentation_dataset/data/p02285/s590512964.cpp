#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define NIL -1
using namespace std;
 
typedef struct{
    int key;
    int right;
    int left;
    int parent;
}node;
 
void insert(vector<node> &T, int i, int *root) {
    int x=*root, y = NIL;
    while(x != NIL){
        y = x;
        T[i].key<T[x].key?x=T[x].left:x=T[x].right;
    }
    T[i].parent = y;
    if(y == NIL) *root = i;
    else if(T[i].key < T[y].key) T[y].left = i;
    else T[y].right = i;
}

void inorder(vector<node> &T, int i){
    if(T[i].left != NIL) 
        inorder(T,T[i].left);
    cout << " " << T[i].key;
    if(T[i].right != NIL)
        inorder(T,T[i].right);
}
 
void preorder(vector<node> &T, int i){
    cout << " " << T[i].key;
    if(T[i].left != NIL)
        preorder(T,T[i].left);
    if(T[i].right != NIL)
        preorder(T,T[i].right);
}
 
int find(vector<node> &T, int i, int k) {
    int result = NIL;
    if(T[i].key == k) return i;
    else if(T[i].key > k) {
        if(T[i].left != NIL)
            result = find(T,T[i].left,k);
    } else if(T[i].key < k) {
        if(T[i].right != NIL)
            result = find(T,T[i].right,k);
    }
    return result;
}

int minimum(vector<node> &T,int a){
    while(T[a].left != NIL) a = T[a].left;
    return a;
}

int successor(vector<node> &T, int z){
    int x = T[z].parent,y;
    if(T[z].right != NIL) return minimum(T,T[z].right);
    while(1) {
        if(x != NIL && T[x].right == z) break;
        y = x;
        x = T[x].parent;
    }
    return x;
}

void erase(vector<node> &T, int *root, int z){
    int x,y;
    T[z].left==NIL||T[z].right==NIL?y = z:y = successor(T,z);
    T[y].left!=NIL?x=T[y].left:x=T[y].right;

    if(x != NIL) T[x].parent = T[y].parent;
    if(T[y].parent == NIL) *root=x;
    else if(y == T[T[y].parent].left) T[T[y].parent].left = x;
    else T[T[y].parent].right = x;

    if(y!=z) T[z].key = T[y].key;
    T[y].parent = NIL;
    T[y].left = NIL;
    T[y].right = NIL;
    T[y].key = 0;
}

int main(void) {
    int judge,n,i,x,root=NIL;
    string od;
    vector<node> T;
    cin >> n;
    T.resize(n);
    rep(i,n) {
        T[i].key = 0;
        T[i].right = NIL;
        T[i].left = NIL;
        T[i].parent = NIL;
    }
    rep(i,n){
        cin >> od;
        if(od == "insert"){
            cin >> T[i].key;
            insert(T,i,&root);
        } else if(od == "print") {
            inorder(T,root);
            cout << endl;
            preorder(T,root);
            cout << endl;
        } else if(od == "find") {
            cin >> x;
            judge = find(T,root,x);
            if(judge != NIL) cout << "yes";
            else cout << "no";
            cout << endl;
        } else if(od == "delete"){
            cin >> x;
            judge = find(T,root,x);
            if(judge != NIL) erase(T,&root,judge);
        }
    }
    return 0;
}