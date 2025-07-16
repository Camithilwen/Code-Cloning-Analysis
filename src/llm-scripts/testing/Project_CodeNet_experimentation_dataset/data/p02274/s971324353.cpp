#include <stdio.h>
#include <limits.h>
#include <algorithm>
 
using namespace std;
 
long long int sum = 0;
 
 
void merge(int A[],int left,int mid, int right){
    int a1 = mid - left;
    int a2 = right - mid;
    int l[a1+1],r[a2+1];
    for(int i = 0; i < a1; i++) l[i] = A[left + i];
    for(int i = 0; i < a2; i++) r[i] = A[mid + i];
    l[a1] = r[a2] =  INT_MAX;
 
    int i = 0, j = 0;
    for(int k = left;k < right; k++){
        if(l[i] < r[j]){
            A[k] = l[i++];
        }else{
            A[k] = r[j++];
            sum += a1 - i;
        }
    }
}
 
void mergeSort(int A[],int left,int right){
    if(left+1 < right){
        int mid = (left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}
 
int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i = 0; i < n; i++) scanf("%d",&A[i]);
 
    mergeSort(A,0,n);
 
    printf("%lld\n",sum);
 
}
