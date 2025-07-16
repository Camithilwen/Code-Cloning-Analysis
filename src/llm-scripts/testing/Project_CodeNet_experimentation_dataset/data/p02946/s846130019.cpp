#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

/*2進数配列+1*/
vector<int> twoadd(vector<int> v, int N){
    v[N-1]+=1;
    int ind = N-1;
    int j=N-1;
    for(j=N-1;j>=1;j--){
        if(v[j]>1){
            v[j-1]+=1;
            v[j]=0;
        }
    }
    return v;
}

/*フィボナッチ*/
long long fibonatti(long long d){
    long long count = 0;
    long long f1 = 1;
    long long f2 = 1;/*ここを変える*/
    long long temp;
    if(d == 1){
        count = f1;
    }else if(d == 2){
        count = f2;
    }else if(d==0){
        count = 1;
    }else{
        for(int i=0;i<d-2;i++){
            temp = f1+f2;
            f1 = f2;
            f2 = temp;
        }
        count = temp;
    }
    return count;
}

/*最大公約数*/
unsigned long long GCD(long long L,long long R){
    if(L>R){
        long long temp=R;
        R = L;
        L = temp;
    }
    unsigned long long pp=0,ppt=0;
    unsigned long long ans=0;
    if(R%L==0){
        ans = L;
    }else{
        while(true){
            ppt = pp;
            pp=R%L;
            if(pp == 0){
                ans = ppt;
                break;
            }
            R = L;
            L = pp;
        }
    }    
    return ans;    
}

/*最小公倍数*/
unsigned long long LCM(long long L,long long R){
    unsigned long long ans;
    unsigned long long gcd = GCD(L,R);
    ans = (L/gcd)*R;
    return ans;
}

/*Combination set*/
#define mod 1000000007
#define maxcomb 3000/*大きいものを求めるときはここを変える*/
vector<long long> fc(maxcomb+1);
vector<long long> ifc(maxcomb+1);
long long modpow(long long x,long long n){
    long long ans = 1;
    while(n > 0){
        if(n & 1) {
            ans = ans*x%mod;
        }
        x = x*x%mod;
        n >>= 1;
    }
    return ans;
}
void Conb(){
    fc[0]= 1;
    ifc[0]=1;
    for(long long i=0;i<maxcomb;i++){
        fc[i+1] = fc[i]*(i+1)%mod;//n!(mod)
        ifc[i+1] = ifc[i]*modpow(i+1,mod-2)%mod;//k!^{M-2} (mod)
    }
}
unsigned long long Combination(long long L,long long R){
    unsigned long long up=1,ans;
    Conb();
    if(L==0&&R==0){
        return 1;
    }else if(L<R||L<0){
        return 0;
    }else{
        long long t = ifc[L-R]*ifc[R]%mod;
        ans = t*fc[L]%mod;
    }
    return ans;
}
/*Combination set ここまで*/

/*ここから*/
int main() {
    int K,X;
    cin >> K >> X;
    for(int i=X-K+1;i<X+K;i++){
        cout << i ;
        if(i!=X+K-1){
            cout << " ";
        }else{
            cout << endl;
        }
    }
    return 0;
}