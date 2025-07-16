#include<cstdio>
char s[1000005];
long long sumM[1000005];

long long solve(int n,int k){
    long long res = 0;
    long long cnt = 0, sum = 0;
    for(int i = 1; i <= n; i++){
        int delet = i-k;
        if(delet>=1 && s[delet]=='D'){
            long long minus = sumM[i-1]-sumM[delet];
            sum -= minus;
            cnt--;
        }
        if(s[i]=='D') cnt++;
        else if(s[i]=='M') sum += cnt;
        else if(s[i]=='C') res += sum;
    }
    return res;
}

int main(){
    int n;
    scanf("%d%s",&n,s+1);
    sumM[0] = 1;
    for(int i = 1; i <= n; i++) sumM[i] = sumM[i-1]+(s[i]=='M');
    int q;
    scanf("%d",&q);
    while(q--){
        int k;
        scanf("%d",&k);
        printf("%lld\n",solve(n,k));
    }
    
    return 0;
}
