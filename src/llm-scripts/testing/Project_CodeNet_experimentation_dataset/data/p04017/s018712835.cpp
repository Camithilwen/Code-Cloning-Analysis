#include<bits/stdc++.h>
using namespace std;

long long nexta[18][100001];

long long arr(long long from, long long days){
    long long shisu=0;
    while(days>0){
        if(days%2==1){
            from=nexta[shisu][from];
        }
        days/=2;
        shisu++;
    }
    return from;
}

int main(){
    //input
    long long N;
    cin >> N;
    long long x[N+1];
    long long i,j;
    for(i=1; i<=N; i++){
        cin >> x[i]; 
    }
    long long L;
    cin >> L;
    long long Q;
    cin >> Q;
    long long a[Q+1], b[Q+1];
    for(i=1; i<=Q; i++){
        cin >> a[i] >> b[i];
        if(a[i]>b[i]) swap(a[i],b[i]);
    }

    //calc
    for(i=1; i<=N; i++){
        j=lower_bound(x+1,x+N+1,x[i]+L)-x;
        if(j>N){
            nexta[0][i]=N;
            continue;
        }
        if(x[i]+L<x[j]){
            j--;
        }
        nexta[0][i]=j;
    }
    for(i=1; i<18; i++){
        for(j=1; j<=N; j++){
            nexta[i][j]=nexta[i-1][nexta[i-1][j]];
        }
    }
    long long ans[Q+1];
    long long lef, rig, mid;
    long long arrarr, arrarrarr;
    for(i=1; i<=Q; i++){
        lef=0;
        rig=N;
        while(lef<rig-1){
            mid=(lef+rig)/2;
            arrarr=arr(a[i],mid-1);
            if(arrarr>=b[i]){
                rig=mid;
            }else{
                lef=mid;
            }
        }
        ans[i]=lef;
    }


    //output
    for(i=1; i<=Q; i++){
        cout << ans[i] << endl;
    }
    system("pause");
    return 0;
}