#include<bits/stdc++.h>
using namespace std;

#define int long long 

void read(int &x) {
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}

void print(int x) {
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
void write(int x) {if(!x) putchar('0');else print(x);putchar('\n');}

#define lf double
#define ll long long 

#define pii pair<int,int >
#define vec vector<int >

#define pb push_back
#define mp make_pair
#define fr first
#define sc second

#define data asd09123jdf02i3h

#define FOR(i,l,r) for(int i=l,i##_r=r;i<=i##_r;i++)

const int maxn = 1e6+10;
const int inf = 1e9;
const lf eps = 1e-8;
const int mod = 1e9+7;

int n,m,b[maxn],l[maxn],r[maxn],ans,s[maxn],t[maxn];

int check(int x) {
    for(int i=1;i<=n;i++) {
        int c=x/m,d=x%m;
        int res=l[i]*min(b[i],d)+r[i]*max(0ll,d-b[i]),w=l[i]*b[i]+r[i]*(m-b[i]);// write(t[c+1]);
        if(c) {
            if(w<s[c]) res+=t[c];
            else res+=t[c+1]-w;
        }
        res-=ans;// printf("%I64d %I64d %I64d\n",x,i,res);
        if(res>=0) return 1;
    }
    return 0;
}

signed main() {
    read(n),read(m);
    for(int i=1;i<=n;i++) read(b[i]),read(l[i]),read(r[i]),ans+=b[i]*l[i],s[i]=b[i]*l[i]+(m-b[i])*r[i];
    sort(s+1,s+n+1,greater<int > ());
    for(int i=1;i<=n;i++) t[i]=s[i]+t[i-1];
    int l=0,r=n*m,ans=n*m;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    write(ans);
    return 0;
}
