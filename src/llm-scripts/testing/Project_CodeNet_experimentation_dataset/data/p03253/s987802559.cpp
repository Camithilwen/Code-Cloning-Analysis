
#include<cstdio>
const int mod=1000000007;
long long power(long long a,int k){
    long long ans=1,y=a;
    while(k){
        if(k%2)
            ans=ans*y%mod;
        y=y*y%mod;
        k=k/2;
    }
    return ans;
}
long long fun[1<<17],ans=1;
int main(){
    long long n,m;
    scanf("%lld%lld",&n,&m);
    fun[0]=1;
    for(int i=1;i<1<<17;i++){
        fun[i]=fun[i-1]*i%mod;
    }
    for(int i=2;i*i<=m;i++){
        if(m%i==0){
            long long s=0;
            while (m%i==0) {
                m=m/i;
                s++;
            }
            ans=ans*fun[n+s-1]%mod*power(fun[n-1], mod-2)%mod*power(fun[s], mod-2)%mod;
        }
    }
    if(m>1)
        ans=ans*n%mod;
    printf("%lld\n",ans);
    return 0;
}