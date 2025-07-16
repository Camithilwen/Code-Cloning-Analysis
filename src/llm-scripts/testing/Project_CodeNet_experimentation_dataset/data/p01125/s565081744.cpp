#include <stdio.h>

int main(){
    int n,m,i,j,x[20],y[20],z[30],p[31],q[31],a[20],b[20],c[20],s;
    char d[i];
    while(1) {
        scanf("%d",&n);
        if (n==0) break;
        for (i=0;i<n;i++) {
            scanf("%d %d",&x[i],&y[i]);
        }
        scanf("%d",&m);
        for (i=0;i<m;i++) {
            getchar();
            scanf("%c %d",&d[i],&z[i]);
        }
        p[0]=10;
        q[0]=10;
        for (i=0;i<m;i++) {
            p[i+1]=p[i];
            q[i+1]=q[i];
            if (d[i]=='N') {q[i+1]=q[i]+z[i];}
            if (d[i]=='S') {q[i+1]=q[i]-z[i];}
            if (d[i]=='E') {p[i+1]=p[i]+z[i];}
            if (d[i]=='W') {p[i+1]=p[i]-z[i];}
        }
        s = 1;
        for (i=0;i<n;i++) {
            c[i] = 0;
            for (j=0;j<m;j++) {
                a[i] = b[i] = 0;
                if ((x[i]<=p[j]&&x[i]>=p[j+1])||(x[i]>=p[j]&&x[i]<=p[j+1])) {
                    a[i]=1;
                }
                if ((y[i]<=q[j]&&y[i]>=q[j+1])||(y[i]>=q[j]&&y[i]<=q[j+1])) {
                    b[i]=1;
                }
                c[i] |= a[i]*b[i];
            }
        }
        for (i=0;i<n;i++) {
            s*=c[i];
        }
        if (s==1) {printf("Yes\n");}
        if (s!=1) {printf("No\n");}
    }
    return 0;
}