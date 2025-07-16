#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Set;

const int RLEN=1<<18|1;
inline char nc() {
    static char ibuf[RLEN],*ib,*ob;
    (ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
    return (ib==ob) ? -1 : *ib++;
}
inline int rd() {
    char ch=nc(); int i=0,f=1;
    while(!isdigit(ch)) {if(ch=='-')f=-1; ch=nc();}
    while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}
    return i*f;
}

const int N=3e5+50;
int n,a[N][3],inv0,inv1,flip0,flip1;
int p0[N],p1[N];
inline void calc(int &inv,int *p,int nn) {
    Set S;
    static int pos[N];
    for(int i=1;i<=nn;i++) pos[p[i]]=i;
    for(int i=1;i<=nn;i++) S.insert(i);
    for(int i=1;i<=nn;i++) {
        inv+=S.order_of_key(pos[i]+1)-1;
        inv%=2; S.erase(pos[i]);
    } return;
}
int main() {
    n=rd(); 
    for(int j=0;j<3;j++) for(int i=1;i<=n;i++) a[i][j]=rd()-1;
    for(int i=1;i<=n;i+=2) {
      //  cerr<<i<<'\n';
        if(a[i][0]/6!=a[i][1]/6 || a[i][0]/6!=a[i][2]/6) {puts("No"); return 0;}
        else if(a[i][1]%6!=1) {puts("No"); return 0;}
        else if(a[i][0]%6+a[i][2]%6!=2) {puts("No"); return 0;}
        if(a[i][0]%6) ++flip1;
        p1[(i+1)/2]=a[i][0]/6+1;
    }
    for(int i=2;i<=n;i+=2) {
        if(a[i][0]/6!=a[i][1]/6 || a[i][0]/6!=a[i][2]/6) {puts("No"); return 0;}
        else if(a[i][1]%6!=4) {puts("No"); return 0;}
        if(a[i][0]%6==5) ++flip0;
        p0[i/2]=a[i][0]/6+1;
    }
    calc(inv0,p0,n/2); calc(inv1,p1,(n+1)/2);
    if((inv0^flip1)&1) {puts("No"); return 0;}
    if((inv1^flip0)&1) {puts("No"); return 0;}
    puts("Yes"); return 0;
}