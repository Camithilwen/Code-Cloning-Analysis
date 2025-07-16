#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
 
typedef long long ll;
const int MAXN=1e7+5;
 
int n,ans;
int deq[MAXN],l,r;
char s[MAXN],t[MAXN];
 
int main(){
 
    scanf("%d%s%s",&n,s+1,t+1);
    if(strcmp(s+1,t+1)==0) return puts("0"),0;
    l=1,r=0;
    for(int i=n,j=n;i>=1;i--){
        if(t[i]==t[i-1]) continue;
        j=min(i,j);
        while(j&&t[i]!=s[j]) j--;
        if(!j) return puts("-1"),0;
        while(l<=r){
            if(deq[l]-(r-l)>i) l++;
            else break;
        }
        deq[++r]=j;
        if(i!=j) ans=max(ans,r-l+1);
    }
    printf("%d",ans+1);
 
    fclose(stdin);
    fclose(stdout);
}