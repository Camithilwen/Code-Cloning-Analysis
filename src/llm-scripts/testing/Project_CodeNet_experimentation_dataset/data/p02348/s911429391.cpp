#include <stdio.h>
const int INF=2147483647;
struct segment_tree{
    int map[2000010];
    void build(int now,int l,int r){
        if(l==r){
            map[now]=INF;
            return;
        }
        map[now]=-1;
        int mid=(l+r)/2;
        build(now*2+1,l,mid);
        build(now*2+2,mid+1,r);
        return ;
    }
    void change(int n,int now,int L,int R,int l,int r){
        if(R<l||L>r)return;
        if(L>=l&&R<=r){
            map[now]=n;
            return;
        }
        if(map[now]!=-1){
            map[now*2+1]=map[now*2+2]=map[now];
            map[now]=-1;
        }
        int mid=(L+R)/2;
        change(n,now*2+1,L,mid,l,r);
        change(n,now*2+2,mid+1,R,l,r);
        return ;
    }
    int find(int now,int L,int R,int n){
        if(L==R)return map[now];
        if(map[now]!=-1){map[now*2+1]=map[now*2+2]=map[now];
            int temp=map[now];
            map[now]=-1;
            return temp;
        }
        int mid=(L+R)/2;
        if(mid>=n)return find(now*2+1,L,mid,n);
        else return find(now*2+2,mid+1,R,n);
    }
};
int main(){
    int n,m,k,l,r;
    segment_tree arr;
    scanf("%d%d",&n,&m);
    arr.build(0,0,n-1);
    while(m--){
        scanf("%d",&k);
        if(k==0){
            scanf("%d%d%d",&l,&r,&k);
            arr.change(k,0,0,n-1,l,r);
        }
        else {
            scanf("%d",&k);
            printf("%d\n",arr.find(0,0,n-1,k));
        }
    }
    
}