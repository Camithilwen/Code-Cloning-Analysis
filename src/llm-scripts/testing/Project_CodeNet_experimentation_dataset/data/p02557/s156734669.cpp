#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N],b[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=n;i>=1;i--) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        if(a[i]==b[i]){
            bool flag=0;
            for(int j=1;j<=n;j++){
                if(b[j]!=a[i]&&b[i]!=a[j]){
                    swap(b[i],b[j]);
                    flag=1;
                    break;
                }
            }
            if(!flag){
                printf("No");
                return 0;
            }
        }
    }
    printf("Yes\n");
    for(int i=1;i<=n;i++) printf("%d ",b[i]);
    return 0;
}