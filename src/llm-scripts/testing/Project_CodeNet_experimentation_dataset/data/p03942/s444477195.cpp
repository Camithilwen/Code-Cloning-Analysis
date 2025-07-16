#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int N=1000005;
int n,pos,ans,head,tail,q[N];
char s[N],t[N];
int main(){
    scanf("%d%s%s",&n,s+1,t+1);
    if(!strcmp(s+1,t+1)){
        puts("0");
        return 0;
    }
    pos=n;
    head=1,tail=0;
    for(int i=n;i>=1;i--){
        if(t[i]==t[i-1]){
            continue;
        }
        pos=min(pos,i);
        while(pos&&t[i]!=s[pos]){
            pos--;
        }
        if(!pos){
            puts("-1");
            return 0;
        }
        while(head<=tail){
            if(q[head]-(tail-head+1)+1>i){
                head++;
            }else{
                break;
            }
        }
        q[++tail]=pos;
        if(i!=pos){
            ans=max(ans,tail-head+1);
        }
    }
    printf("%d\n",ans+1);
    return 0;
}