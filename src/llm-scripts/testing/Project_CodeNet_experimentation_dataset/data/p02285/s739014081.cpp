#include <stdio.h>
struct binary_tree{
    int n;
    int l;
    int r;
};
binary_tree bt[1000000];
int now=0,empty[1000000];
void push(int n,int t){
    if(now==0){
        bt[0].n=n;
        now++;
        return;
    }
    if(bt[t].n<n){
        if(bt[t].r==0){
            bt[t].r=empty[now];
            bt[bt[t].r].n=n;
            now++;
            return;
        }
        else push(n,bt[t].r);
    }
    if(bt[t].n>n){
        if(bt[t].l==0){
            bt[t].l=empty[now];
            bt[bt[t].l].n=n;
            now++;
            return;
        }
        else push(n,bt[t].l);
    }
}
void dfs(int n){
    printf(" %d",bt[n].n);
    if(bt[n].l!=0){
        dfs(bt[n].l);
    }
    if(bt[n].r!=0){
        dfs(bt[n].r);
    }
}
void print_sorted(int n){
    if(bt[n].l!=0){
        print_sorted(bt[n].l);
    }
    printf(" %d",bt[n].n);
    if(bt[n].r!=0){
        print_sorted(bt[n].r);
    }
}
bool find(int n,int t){
    if(bt[t].n==n)return true;
    if(bt[t].n<n){
        if(bt[t].r!=0)return find(n,bt[t].r);
        return false;
    }
    if(bt[t].l!=0)return find(n,bt[t].l);
    return false;
}
void delete_item(int n,int t,int p){
    if(bt[t].n==n){
        if(bt[t].r!=0&&bt[t].l!=0){
            int big=bt[t].r,bp=t;
            while(bt[big].l!=0){
                bp=big;
                big=bt[big].l;
            }
            bt[t].n=bt[big].n;
            if(bp!=t)bt[bp].l=bt[big].r;
            else bt[bp].r=bt[big].r;
            now--;
            empty[now]=big;
            bt[big].n=bt[big].l=bt[big].r=0;
            return;
        }
        if(bt[t].r==0){
            if(p==-1){
                now--;
                empty[now]=bt[t].l;
                bt[t]=bt[bt[t].l];
                bt[empty[now]].n=bt[empty[now]].l=bt[empty[now]].r=0;
                return;
            }
            if(bt[p].n>n)bt[p].l=bt[t].l;
            else bt[p].r=bt[t].l;
            now--;
            empty[now]=t;
            bt[empty[now]].n=bt[empty[now]].l=bt[empty[now]].r=0;
            return;
        }
        if(bt[t].l==0){
            if(p==-1){
                now--;
                empty[now]=bt[t].r;
                bt[t]=bt[bt[t].r];
                bt[empty[now]].n=bt[empty[now]].l=bt[empty[now]].r=0;
                return;
            }
            if(bt[p].n>n)bt[p].l=bt[t].r;
            else bt[p].r=bt[t].r;
            now--;
            empty[now]=t;
            bt[empty[now]].n=bt[empty[now]].l=bt[empty[now]].r=0;
            return;
        }
    }
    else if(bt[t].n>n){
        delete_item(n,bt[t].l,t);
        return;
    }
    else delete_item(n,bt[t].r,t);
}
int main(){
    int n,temp;
    char a[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        empty[i]=i;
        bt[i].n=bt[i].l=bt[i].r=0;
        scanf("%s",a);
        if(a[0]=='i'){
            scanf("%d",&temp);
            push(temp,0);
        }
        if(a[0]=='p'){
            print_sorted(0);
            printf("\n");
            dfs(0);
            printf("\n");
        }
        if(a[0]=='f'){
            scanf("%d",&temp);
            if(find(temp,0))printf("yes\n");
            else printf("no\n");
        }
        if(a[0]=='d'){
            scanf("%d",&temp);
            delete_item(temp,0,-1);
        }
    }
}