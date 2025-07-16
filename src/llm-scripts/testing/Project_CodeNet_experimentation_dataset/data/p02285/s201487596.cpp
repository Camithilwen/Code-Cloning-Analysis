#include<bits/stdc++.h>
using namespace std;
#define NIL 2000000001
typedef struct{
  int p,l,r,key; 
}node;

node tree[500001];
queue<int> q[2];
int root=NIL;

void insert(int key,int i){
  node z={NIL,NIL,NIL,key};
  int x=(root==NIL?NIL:root),y=NIL;
  if(root==NIL)root=i;
  while(x!=NIL){
    y=x;
    if(z.key<tree[x].key){
      x=tree[x].l;
    }else{
      x=tree[x].r;
    }
  }
  z.p=y;
  if(y==NIL){
    tree[0]=z;
  }else if(z.key<tree[y].key){
    tree[y].l=i;
  }else {
    tree[y].r=i;
  }
  tree[i]=z;
}

void print(int n=0){
  if(n==NIL)return;
  q[1].push(tree[n].key);
  print(tree[n].l);
  q[0].push(tree[n].key);
  print(tree[n].r);
}

int find(int key){
  int f=-1,x=root;
  while(x!=NIL){
    if(tree[x].key>key){
      x=tree[x].l;
    }else if(tree[x].key<key){
      x=tree[x].r;
    }else{
      f=x;
      break;
    }
  }
  return f;
}

void del(int k){
  int x=find(k);
  if(x==-1)return;
  if(tree[x].l==NIL&&tree[x].r==NIL){
    
    if(tree[tree[x].p].l==x){
      tree[tree[x].p].l=NIL;
    }else{
      tree[tree[x].p].r=NIL;
    }
    
  }else if(tree[x].l==NIL||tree[x].r==NIL){
    
    if(tree[x].l==NIL){
      if(tree[tree[x].p].l==x){
	tree[tree[x].r].p=tree[x].p;
	tree[tree[x].p].l=tree[x].r;
      }else{
	tree[tree[x].r].p=tree[x].p;
	tree[tree[x].p].r=tree[x].r;
      }
    }else{
      if(tree[tree[x].p].l==x){
	tree[tree[x].l].p=tree[x].p;
	tree[tree[x].p].l=tree[x].l;
      }else{
	tree[tree[x].l].p=tree[x].p;
	tree[tree[x].p].r=tree[x].l;
      }
    }
  }else{
    int dx=tree[x].r;
    while(tree[dx].l!=NIL)dx=tree[dx].l;
    tree[x].key=tree[dx].key;
    if(tree[dx].l==NIL&&tree[dx].r==NIL){
      
      if(tree[tree[dx].p].l==dx){
	tree[tree[dx].p].l=NIL;
      }else{
	tree[tree[dx].p].r=NIL;
      }
      
    }
    else{
      if(tree[dx].l==NIL){
	if(tree[tree[dx].p].l==dx){
	  tree[tree[dx].r].p=tree[dx].p;
	  tree[tree[dx].p].l=tree[dx].r;
	}else{
	  tree[tree[dx].r].p=tree[dx].p;
	  tree[tree[dx].p].r=tree[dx].r;
	}
      }else{
	if(tree[tree[dx].p].l==dx){
	  tree[tree[dx].l].p=tree[dx].p;
	  tree[tree[dx].p].l=tree[dx].l;
	}else{
	  tree[tree[dx].l].p=tree[dx].p;
	  tree[tree[dx].p].r=tree[dx].l;
	}
      }
    }
  }
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string a;
    cin>>a;
    
    if(a[0]=='i'){   
      int k;
      cin>>k;
      insert(k,i);
      
    }else if(a[0]=='f'){
      int key;
      cin>>key;
      cout<<(find(key)>=0?"yes":"no")<<endl;
    }else if(a[0]=='d'){
      int key;
      cin>>key;
      del(key);
    }else{
      print();
      for(int j=0;j<2;j++){
	while(!q[j].empty()){
	  cout<<" "<<q[j].front();
	  q[j].pop();
	}
	cout<<endl;
      }
    }
  }
  return 0;
}