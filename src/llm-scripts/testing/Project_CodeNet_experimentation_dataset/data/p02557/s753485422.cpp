#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int a[maxn],b[maxn];
int main(){ 
    int n;
    vector<int>p;
    cin>>n;
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)scanf("%d",&b[i]);
    reverse(b+1,b+n+1);
    int h1=n,q1=1,mx;
    for(int i=1;i<=n;++i){ 
        if(a[i]==b[i]){ 
            mx=a[i];
            h1=i;
            while(a[i]==b[i]){ 
                i++;
            }
            q1=i-1;
            break;
        }
    }
    for(int i=1;i<=n;++i){ 
        if(a[i]!=mx&&b[i]!=mx&&h1<=q1){ 
            swap(b[i],b[h1]);
            h1++;
        }    
    }
    if(h1<=q1){ puts("No");return 0;}
    puts("Yes");
    for(int i=1;i<n;++i)
        printf("%d ",b[i]);
    printf("%d\n",b[n]);
}
