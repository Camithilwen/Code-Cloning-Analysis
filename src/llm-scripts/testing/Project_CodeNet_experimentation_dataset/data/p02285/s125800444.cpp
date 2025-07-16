#include <cstdio>
#include <vector>

using namespace std;

struct node{
    int key;
    int parent, left, right;
    node(){ parent=-1; left=-1; right=-1; }
};

vector<node> tree;
int root=-1;

void print_pre(int id)
{
    if(id==-1){ return; }
    printf(" %d", tree[id].key);
    print_pre(tree[id].left);
    print_pre(tree[id].right);
}

void print_in(int id)
{
    if(id==-1){ return; }
    print_in(tree[id].left);
    printf(" %d", tree[id].key);
    print_in(tree[id].right);
}

void insert(int z)
{
    int y=-1;
    int x=root;
    while(x!=-1){
        y=x;
        if(tree[z].key<tree[x].key){
            x=tree[x].left;
        } else{
            x=tree[x].right;
        }
    }
    tree[z].parent=y;
    if(y==-1){
        root=z;
    } else if(tree[z].key<tree[y].key){
        tree[y].left=z;
    } else{
        tree[y].right=z;
    }
}

int find(int key)
{
    int x=root;
    while(x!=-1){
        int k=tree[x].key;
        if(key==k){
            return x;
        } else if(key<k){
            x=tree[x].left;
        } else{
            x=tree[x].right;
        }
    }
    return -1;
}

void delete_(int z)
{
    auto which=[](int z){
        auto p=&tree[tree[z].parent];
        if(p->left==z){
            return &p->left;
        } else{
            return &p->right;
        }
    };

    if(tree[z].left!=-1 && tree[z].right!=-1){
        int x=tree[z].right;
        while(tree[x].left!=-1){
            x=tree[x].left;
        }
        tree[z].key=tree[x].key;
        z=x;
    }

    if(tree[z].left==-1 && tree[z].right==-1){
        if(tree[z].parent!=-1){
            *(which(z))=-1;
        } else{
            root=-1;
        }
    } else if(tree[z].left!=-1){
        if(tree[z].parent!=-1){
            *(which(z))=tree[z].left;
        } else{
            root=tree[z].left;
        }
        tree[tree[z].left].parent=tree[z].parent;
    } else{
        if(tree[z].parent!=-1){
            *(which(z))=tree[z].right;
        } else{
            root=tree[z].right;
        }
        tree[tree[z].right].parent=tree[z].parent;
    }
}

int main()
{
    int m;
    scanf("%d", &m);
    tree=vector<node>(m);
    int n=0;
    for(int i=0; i<m; i++){
        char buf[8]; scanf("%s", buf);
        if(*buf=='i'){
            int k; scanf("%d", &k);
            tree[n].key=k;
            insert(n);
            n++;
        } else if(*buf=='f'){
            int k; scanf("%d", &k);
            printf("%s\n", find(k)!=-1 ? "yes" : "no");
        } else if(*buf=='d'){
            int k; scanf("%d", &k);
            int id=find(k);
            if(id!=-1){
                delete_(id);
            }
        } else{
            print_in(root);
            printf("\n");
            print_pre(root);
            printf("\n");
        }
    }
    return 0;
}