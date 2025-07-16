#include <cstdio>
using namespace std;
int main()
{
    int n;
    bool prime[10001];
    for (int i=0; i<=10000; i++) prime[i]=true;
    prime[0]=false;
    prime[1]=false;
    for (int i=2; i<=10000; i++) {
        if (!prime[i]) continue;
        for (int j=i+i;j<=10000; j+=i) prime[j]=false;
    }
    while (scanf("%d",&n)&&n!=0) {
        int p1=0, p2=0;
        for (int i=2; i+2<=n; i++) {
            if (!prime[i]) continue;
            if (prime[i]&&prime[i+2]) {
                p1=i;
                p2=i+2;
            }
        }
        printf("%d %d\n",p1,p2);
    }
}