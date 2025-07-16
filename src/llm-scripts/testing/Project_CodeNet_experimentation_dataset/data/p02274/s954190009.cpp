#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll /*A[2000000],*/ cnt = 0;
int A[210000];
int L[110001];
int R[110001];
 
int merge(int l, int m, int r){
    int n1 = m - l, n2 = r - m, i, j;
    //ll L[n1 + 1], R[n2 + 1];
    for(i = 0;i < n1;i++)L[i] = A[i + l];
    for(i = 0;i < n2;i++)R[i] = A[i + m];
    i = j = 0;
    for(int k = 0;k < r - l;k++){
        if(j == n2 || (i < n1 && L[i] <= R[j]))A[k + l] = L[i++];
        else A[k + l] = R[j++], cnt += n1 - i;
    }
}

int mergeSort(int l, int r){
    if(l + 1 < r){
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m, r);
        merge(l, m, r);
    }
}
 
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)scanf("%d", &A[i]);
	mergeSort(0, n);
	printf("%lld\n", cnt);
     
    return 0;
}