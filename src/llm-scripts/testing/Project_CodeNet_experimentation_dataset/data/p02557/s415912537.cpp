#include<bits/stdc++.h>
using namespace std;
inline int read(){
    char c=getchar(); int res=0;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)){ res=(c&15)+(res<<1)+(res<<3); c=getchar(); }
    return res;
}
int n,*a,*b;
int main(){
    n=read();
    a=new int[n]; b=new int[n+1];
    pair<int,int>*bound=new pair<int,int>[n+1];
    for(int i=0;i<=n;i++) bound[i]=make_pair(-1,-1);
    for(int i=0,cur=0;i<n;i++){
        a[i]=read();
        if(cur!=a[i]){
            bound[cur].second=i-1;
            bound[a[i]].first=i;
            cur=a[i];
        }
    }
    bound[a[n-1]].second=n-1;
    for(int i=0;i<n;i++) b[i]=read();
    int*off=new int[n+3]; off[0]=0; off++;
    for(int i=0;i<=n+1;i++) off[i]=0;
    for(int i=0,l,r;i<n;i++){
        l=bound[b[i]].first;
        r=bound[b[i]].second;
        if(l!=-1&&r!=-1){
            if(i<l){
                off[l-i]--;
                off[r-i+1]++;
            }else if(i>r){
                off[n+l-i]--;
                off[n+r-i+1]++;
            }else{
                off[0]--;
                off[r-i+1]++;
                off[n+l-i]--;
            }
        }
    }
    for(int i=0;i<n;i++) off[i]+=off[i-1];
    int res=-1;
    for(int i=0;i<n;i++){
        if(off[i]==0){
            res=i;
            break;
        }
    }
    if(res==-1){
        printf("No");
    }else{
        printf("Yes\n");
        for(int i=n;i<n<<1;i++){
            printf("%d ",b[(i-res)%n]);
        }
    }
    return 0;
}