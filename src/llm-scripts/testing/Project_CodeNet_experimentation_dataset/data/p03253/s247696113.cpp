#include"bits/stdc++.h"

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)

const long long INF10=1e10+1,ID_MAX=20;
const long mod=(1e9)+7;
const long long INF18=1e18+1;

struct edge{
    int to;
    long cost;
};

void sort2array(double *a,long *b,long n){
    for(int i=0;i<n;i++){
        b[i]=i;
    }
    sort(b,b+n,[a](long i,long j)->bool {return a[i]<a[j];} );
}
//bを何回足せばaを超えるか(O(a/b))
int wtover(int a,int b){
    if(a%b>0)return (a/b)+1;
    else return a/b;
}
int bi_e[ID_MAX]={0};
//2進数表示したときの最高桁(O(log n))
int bi_max(long n){
    int m=0;
    for(m;(1<<m)<=n;m++);m=m-1;
    return m;
}
//bi_eに二進数表示したやつを代入(O(log^2 n))
void bi_exs(long n){
    memset(bi_e,0,sizeof(bi_e));
    if(n<(1<<ID_MAX)){
        for(int i=0;n>0;n=(n>>1),i++)bi_e[i]=n&1;
    }
}
//x^n mod m (nが負の時は０)(O(log n))
long myPow(long x, long n, long m){
  if(n<0)return 0;
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}
//m以下のn以下の分割数のmodの表生成(O(nm))d[i][j]=jのi分割
long long d[10001][10001];
void divNum(int n,int m,long long md=mod){
    rep(j,n+1){
        d[j][0]=1;
    }
    rep(j,m){
        d[0][j+1]=0;
    }
    for(int j=1;j<=n;j++){
        for(int k=1;k<=m;k++){
            if(j>k)d[j][k]=d[j-1][k];
            else d[j][k]=(d[j-1][k]+d[j][k-j])%md;
        }
    }
}
const int N_MAX=1e5+1,M_MAX=1e9+1;
int n,m;
vector<int> a;
long long div_res[N_MAX][100];
void divide(int s,int t){
    div_res[0][0]=1;
    rep(i,s){
        rep(j,t+1){
            rep(k,t-j+1){
                div_res[i+1][j+k]=(div_res[i+1][j+k]+div_res[i][j])%mod;
            }
        }
    }
}

int main(){
    int i=0,maxa=0;
    //入力
    cin>>n>>m;
    int mm=m,x=2,r;
    for(int j=2;j<=ceil(sqrt(m));j++){
        r=0;
        while(mm%j==0){
            mm=mm/j;
            r++;
        }
        if(r!=0){
            if(maxa<r)maxa=r;
            a.push_back(r);
        }
    }
    if(mm!=1)a.push_back(1);
    //処理
    long long res=1;
    divide(n,maxa);
    rep(i,a.size()){
        res=(res*div_res[n][a.at(i)])%mod;
    }
    //出力
    cout<<res<<endl;
}