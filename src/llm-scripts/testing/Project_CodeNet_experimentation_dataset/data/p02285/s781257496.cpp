#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define N 600000
#define NIL -1

//array
int key[N];
int parent[N];
int leftc[N];
int rightc[N];
//root
int root=NIL;

//function insert
void insert(int z){
  int x,y;
  
  y=NIL;
  x=root;

  while(x!=NIL){
    y=x;
    if(key[z]<key[x]) x=leftc[x];
    else x=rightc[x];
  }  
  
  parent[z]=y;

  if(y==NIL) root=z;
    
  else if(key[z]<key[y]) leftc[y]=z;

  else rightc[y]=z;
  
  
}

//function search
int find(int now,int data){
  if(now==NIL ||data==key[now]) return now;
  
  if(data<key[now]) return find(leftc[now],data);
  else return find(rightc[now],data);
}


int treeminimum(int x){
  while(leftc[x]!=NIL){
    x=leftc[x];
  }
  return x;
}


int treesuccessor(int x){
  int y; 
  if(rightc[x]!=NIL) return treeminimum(rightc[x]);
  y=parent[x];
  while(y!=NIL &&x==rightc[x]){
    x=y;
    y=parent[y];
  }
  return y;
}


//function delete
void treedelete(int z){
  int x,y;
  if(leftc[z]==NIL ||rightc[z]==NIL) y=z;
  else y=treesuccessor(z);

  if(leftc[y]!=NIL) x=leftc[y];
  else x=rightc[y];

  if(x!=NIL) parent[x]=parent[y];
  if(parent[y]==NIL) root=x;
  else if(y==leftc[parent[y]]) leftc[parent[y]]=x;
  else rightc[parent[y]]=x;

  if(y!=z) key[z]=key[y];

}

//print
void inorderprint(int now){
  if(now!=NIL){
    inorderprint(leftc[now]);
    printf(" %d",key[now]);
    inorderprint(rightc[now]);
  }
}

void preorderprint(int now){
  if(now!=NIL){
    printf(" %d",key[now]);
    preorderprint(leftc[now]);
    preorderprint(rightc[now]);
  }
}



int main(){

  int n,i,j,data;
  int z=0;
  int del;
  char str[10];
  //initialize array
  for(i=0;i<N;i++){
    parent[i]=NIL;
    key[i]=NIL;
    rightc[i]=NIL;
    leftc[i]=NIL;
  }
  //load n
  scanf("%d",&n);
  //load commnad and key
  for(i=0;i<n;i++){
    scanf("%s",str);
    if(strcmp(str,"insert")==0) {
      scanf("%d",&data);
      key[z]=data;
      insert(z);
      z++;
    }
    else if(strcmp(str,"find")==0){
      scanf("%d",&data);
      if(find(root,data)!=NIL) printf("yes\n");
      else printf("no\n");
    }
    else if(strcmp(str,"delete")==0){
      scanf("%d",&data);
      del=find(root,data);
      treedelete(del);
    }
    else if(strcmp(str,"print")==0){
      inorderprint(root);
      cout <<endl;
      preorderprint(root);
      cout <<endl;
    }
  }

  return 0;
}