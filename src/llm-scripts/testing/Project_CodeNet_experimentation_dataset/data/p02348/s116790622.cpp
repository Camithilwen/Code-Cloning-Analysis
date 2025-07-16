#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define FORq(i, m, n) for(int i = (m);i <= (n);++i)
#define SCD(n) scanf("%d",&n)
#define SCD2(m,n) scanf("%d%d",&m,&n)
#define SCD3(m,n,k) scanf("%d%d%d",&m,&n,&k)
#define SCLLD(n) scanf("%lld",&n)
#define SCLLD2(m,n) scanf("%lld%lld",&m,&n)
#define SCLLD3(m,n,k) scanf("%lld%lld%lld",&m,&n,&k)
#define PB push_back
#define MP make_pair
#define ARSCD(A,N) REP(i,N){SCD(A[i]);}
#define ARSCD1(A,N) FORq(i,1,N){SCD(A[i]);}
#define PRINTD(n) printf("%d\n",n)
#define PRINTLLD(n) printf("%lld\n",n)
#define DEBUG printf("%s\n","debug")
#define fst first
#define snd second
#define SIN(x,S) (S.count(x) != 0)
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector < VI > VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
//////////////////////////////////////////////////
// Range Query - RMQ and RUQ with Lazy Segment Tree
// https://www.slideshare.net/iwiwi/ss-3578491
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F&lang=jp

struct LazySegmentTree{
    // for vertex n
    // par (n-1)/2
    // chi 2n+1,2n+2

    // index i
    // bottom vertex n+i-1
    const int NONNUM = -1; //ありえない数字
    int segn2; // imply actually vertex number
    vector<ll> data,lazy; 
     
    LazySegmentTree(int n){
        segn2=1;
        while(segn2<n) segn2*=2; //必要分2^Mを取る
         
        data.resize(segn2*2,INT_MAX);
        lazy.resize(segn2*2,NONNUM);
    }
    
    //lazy_propagate -- lazy[v] = xはvの表す区間がxに変更されることを表す．
    inline void eval(int k,int l,int r){
        if (lazy[k] != NONNUM){ // lazy nonzero
            data[k] = lazy[k]; // itself
            
            if (r-l > 1){
                lazy[2*k+1] = lazy[k];
                lazy[2*k+2] = lazy[k];
            }

            lazy[k] = NONNUM;
        }
    }

    ll query(int a,int b,int l=0,int r=-1,int k=0){
        if(r<0) r=segn2; // when calling function at first
        if (r <= a || b <= l) return INT_MAX; //disjoint

        eval(k,l,r);

        if (a <= l && r <= b) return data[k]; //include
        
        ll vl = query(a,b,l,(l+r)/2,k*2+1);
        ll vr = query(a,b,(l+r)/2,r,k*2+2);
        return min(vl,vr);
    }
     
    
    void update(int a,int b ,ll x, int l = 0, int r=-1,int k = 0){
        if(r==-1) r=segn2;

        eval(k,l,r);
        
        if (b <= l || r <= a) return;

        if (a <= l && r <= b){
            lazy[k] = x;
            eval(k,l,r);
            return;
        }else{
            //一部のみ含むとき，子ノードを計算してその結果をもらう
            update(a,b,x,l,(l+r)/2,2*k+1);
            update(a,b,x,(l+r)/2,r,2*k+2);
            data[k] = min(data[2*k+1] , data[2*k+2]);
        }
        
    }
};

// 0-indexed
// sum [s,t) --> s,t+1
// update [s,t,x) --> s,t+1,x

int main(){
    int N,q;
    SCD2(N,q);
    LazySegmentTree seg(N);

    REP(i,q){
        int d; SCD(d);
        if (d==0){
            int s,t,x;
            SCD3(s,t,x);
            seg.update(s,t+1,(ll)x);
        }else{
            int s,t; SCD(s);
            PRINTLLD(seg.query(s,s+1));
        }
    }
}

