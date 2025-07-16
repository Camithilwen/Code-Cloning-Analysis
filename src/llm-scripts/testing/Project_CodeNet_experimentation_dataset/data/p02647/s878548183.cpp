#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define ALL(x) (x).begin(),(x).end()
using namespace std;
const int MAXN = 200005;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int>A(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    int flag= 1;
    while(k--&&flag){
        flag = 0 ;
        vector<int>B(n);
        for(int i=0;i<n;i++){
            B[max(0,i-A[i])]++;
            if(i+A[i]+1<n)
                B[i+A[i]+1]--;
        }
        for(int i=1;i<n;i++){
            B[i]+=B[i-1];
            //cout << B[i] <<" \n"[i=n-1];
            if(B[i]!=n)
                flag=1;
        }
        if(B[0]!=n)
            flag=1;
        A=B;
    }
    for(int i=0;i<n;i++)
    cout <<A[i]<<" ";
    return 0;
}
