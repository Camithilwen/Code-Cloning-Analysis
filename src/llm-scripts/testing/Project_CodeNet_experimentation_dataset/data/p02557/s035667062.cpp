//https://atcoder.jp/contests/abc178/tasks/abc178_f
#include <bits/stdc++.h>

using namespace std;

const int MAXN=2e5+4;
long long a[MAXN];
long long b[MAXN];

int main() {
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    for (int i=0; i<n; i++) {
        cin>>b[i];
    }

    reverse(b, b+n);

#if 0
    cout<<"\n";
    for (int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    for (int i=0; i<n; i++) {
        cout<<b[i]<<" ";
    }
    cout<<"\n";
#endif

    //寻找重合的区间
    int c=-1;
    int l=n;
    int r=-1;
#if 1
    for (int i=0; i<n; i++) {
        if (-1==c && a[i]==b[i]) {
            //第一次出现相等
            c=a[i];
            l=i;
            r=i;
        } else if (-1!=c && a[i]==b[i]) {
            //最后一次出现相等
            r=i;
        }
    }
    //cout<<l<<" "<<r<<"\n";
#else
    l=n;
    r=-1;
    for (int i=0; i<n; i++) {
        if (a[i]==b[i]) {
            c=a[i];
            break;
        }
    }
    for (int i=0; i<n; i++) {
        if (c==a[i] && c==b[i]) {
            l=min(l, i);
            r=max(r, i);
        }
    }
    cout<<l<<" "<<r<<"\n";
#endif

    //交换数据
    for (int i=0; i<n; i++) {
        if (c!=a[i] && c!=b[i] && l<=r) {
            swap(b[i], b[l]);
            l++;
        }
    }

    if (l<=r) {
        cout<<"No\n";
    } else {
        cout<<"Yes\n";
        for (int i=0; i<n; i++) {
            cout<<b[i]<<" ";
        }
    }

    return 0;
}