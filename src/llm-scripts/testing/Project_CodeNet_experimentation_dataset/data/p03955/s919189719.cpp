#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

/*
転倒数を求める
O(NlogN)
*/
int inversion_number(vector<int>dat){
    //座標圧縮
    vector<int>vs;
    for(int i=0;i<dat.size();i++)vs.push_back(dat[i]);
    sort(vs.begin(),vs.end());
    vs.erase(unique(vs.begin(),vs.end()),vs.end());
    for(int i=0;i<dat.size();i++)
        dat[i]=lower_bound(vs.begin(),vs.end(),dat[i])-vs.begin();
    /*
    BIT
    0-indexedで扱う
    点kにxを加算するクエリ、区間[0,x]の和を求めるクエリがO(logN)でできる
    */
    struct binary_indexed_tree{
        vector<int>dat;
        void init(int n){dat=vector<int>(n+1);}
        binary_indexed_tree(int n):dat(n+1){}
        binary_indexed_tree(){}

        void add(int k,int x){
            for(k++;k<dat.size();k+=k&-k)dat[k]+=x;
        }
        int sum(int k){
            int ret=0;
            for(k++;k;k-=k&-k)ret+=dat[k];
            return ret;
        }
    }bit(vs.size());

    int ret=0;
    for(int i=0;i<dat.size();i++){
        ret+=i-bit.sum(dat[i]);
        bit.add(dat[i],1);
    }
    return ret;
}

int N;
int A[100000][3];

signed main(){
    scanf("%lld",&N);
    rep(j,3)rep(i,N)scanf("%lld",&A[i][j]),A[i][j]--;

    vector<int>X[2];
    int x[2]={};
    rep(i,N){
        if(A[i][0]%3)reverse(A[i],A[i]+3),x[i&1]++;
        if(A[i][0]+1!=A[i][1]||A[i][1]+1!=A[i][2]||((A[i][0]/3)&1)!=(i&1)){
            puts("No");
            return 0;
        }
        X[i&1].pb(A[i][0]/3);
    }

    rep(i,2)x[i^1]+=inversion_number(X[i]);
    puts((x[0]%2||x[1]%2)?"No":"Yes");
    return 0;
}
