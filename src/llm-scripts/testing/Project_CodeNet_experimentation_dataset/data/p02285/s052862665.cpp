#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


struct Node{
    ll key;
    Node *parent,*left,*right;
};


struct Tree{
    Node *nil,*root;

    void init(){
        root=nil;
    }

    void add(ll key){
        Node *newnode;
        Node *p;
        newnode = (Node*)malloc(sizeof(Node));

        newnode->key = key;
        newnode->parent = newnode->right = newnode->left = nil;

        Node *pa = find_node(key);
        if(pa == nil){
            root = newnode;
        }else if(key < pa->key){
            pa->left = newnode;
            newnode->parent = pa;
        }else{
            pa->right = newnode;
            newnode->parent = pa;
        }
    }

    Node *find_node(ll key){
        Node *pa=nil;
        Node *loc=root;
        while(loc != nil){
            pa = loc;
            if(key < loc->key){
                loc = loc->left;
            }else{
                loc = loc->right;
            }
        }
        return pa;
    }

    Node *find_x(ll x){
        Node *p=root;
        while(p != nil){
            if(x == p->key){
                break;
            }else if(x < p->key){
                p = p->left;
            }else{
                p = p->right;
            }
        }
        return p;
    }


    ll find_rightmin(Node *r){
        Node *rmin = r->right;
        while(rmin->left != nil){
            rmin = rmin->left;
        }
        return rmin->key;
    }

    void del(ll k){
        Node *loc=find_x(k);
        Node *p=loc->parent;
        if(loc->left==nil && loc->right == nil){
            //leafだったら
            if(p==nil)root=nil;
            else if(p->key > loc->key)p->left=nil;
            else p->right=nil;
            free(loc);
        }else if(loc->left == nil || loc->right==nil){
            //片方だったら
            if(loc->left == nil){
                if(p == nil)root=loc->right, loc->right->parent=root;
                else if(p->key > loc->key)p->left=loc->right, loc->right->parent=p;
                else p->right=loc->right, loc->right->parent=p;
            }else{
                if(loc->parent == nil)root=loc->left, loc->left->parent=nil;
                else if(p->key > loc->key)p->left=loc->left, loc->left->parent=p;
                else p->right=loc->left, loc->left->parent=p;
            }
            free(loc);
        }else{
            //二分木の根だったら
            ll rmin=find_rightmin(loc);
            del(rmin);
            loc->key=rmin;
        }
    }


    void print_in(Node *r){
        if(r==nil)return;
        else{
            print_in(r->left);
            cout << " " << r->key;
            print_in(r->right);
        }
    }

    void print_pre(Node *r){
        if(r==nil)return;
        else{
            cout << " " << r->key;
            print_pre(r->left);
            print_pre(r->right);
        }
    }
    void print(){
        print_in(root);
        cout << endl;
        print_pre(root);
        cout << endl;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Tree tree;
    tree.init();
    int n;
    cin >> n;
    string s;
    for(int i=0;i<n;i++){
        cin >> s;
        if(s=="insert"){
            ll k;
            cin >> k;
            tree.add(k);
        }else if(s=="find"){
            ll k;
            cin >> k;
            Node *p = tree.find_x(k);
            if(p != tree.nil)cout << "yes\n";
            else cout << "no\n";
        }else if(s=="delete"){
            ll k;
            cin >> k;
            tree.del(k);
        }else {
            tree.print();
        }
    }
    return 0;
}

