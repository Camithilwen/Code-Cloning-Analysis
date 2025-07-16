#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
char s[N],a[N];

bool ok(char s[],char a[],int n)
{
    for (int i=1;i<n-1;i++) {
        if (a[i]=='S'&&s[i]=='o' || a[i]=='W'&&s[i]=='x') {
            a[i+1]=a[i-1];
        } else {
            a[i+1]=(a[i-1]=='W')?'S':'W';
        }
    }
    if (a[n-1]=='S'&&s[n-1]=='o' || a[n-1]=='W'&&s[n-1]=='x') {
        if (a[n-2]!=a[0]) return false;
    } else {
        if (a[n-2]==a[0]) return false;
    }
    if (a[0]=='S'&&s[0]=='o' || a[0]=='W'&&s[0]=='x') {
        if (a[n-1]!=a[1]) return false;
    } else {
        if (a[n-1]==a[1]) return false;
    }
    return true;
}

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    bool good=false;
    for (int i=0;i<2;i++) {
        for (int j=0;j<2;j++) {
            a[0]=i?'S':'W';
            a[1]=j?'S':'W';
            if (ok(s,a,n)) {
                puts(a);
                good=true;
                break;
            }
        }
        if (good) break;
    }
    if (!good) {
        puts("-1");
    }
    return 0;
}