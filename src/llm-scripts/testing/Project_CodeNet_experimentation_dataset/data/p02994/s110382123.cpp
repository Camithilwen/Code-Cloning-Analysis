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

/*ここから*/
int main() {
    int N,L;
    cin >> N >> L;
    int R = N+L-1;
    long ans=0;
    if(L>0){
        for(int i=0;i<N;i++){
            ans += L+i;
        }
        cout << ans - L << endl;
    }
    if(L<=0&&R>=0){
        for(int i=0;i<N;i++){
            ans += L+i;
        }
        cout << ans << endl;
    }
    if(R<0){
        for(int i=0;i<N;i++){
            ans += L+i;
        }
        cout << ans-R << endl;
    }
}