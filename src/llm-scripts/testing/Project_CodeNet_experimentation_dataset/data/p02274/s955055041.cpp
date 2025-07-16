#include<bits/stdc++.h>
using namespace std;
long long int cnt=0;
void Merge(int A[],int left,int mid,int right)
{
    int n1=mid-left;
    int n2=right-mid;
    int L[n1+1],R[n2+1];
    int i,j;
    for(i=0;i<n1;++i)
    {
        L[i]=A[left+i];
    }
    for(i=0;i<n2;++i)
    {
        R[i]=A[mid+i];
    }
    L[n1] = R[n2] =  INT_MAX;
    i=0;j=0;
    for(int k=left;k<right;k++)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i++];
        }
        else
        {
            A[k]=R[j++];
            cnt+=n1-i;
        }
    }
}
void mergesort(int A[],int left,int right)
{
    int mid;
    if(left+1<right)
    {
        mid=(left+right)/2;
        mergesort(A,left,mid);
        mergesort(A,mid,right);
        Merge(A,left,mid,right);
    }
}

int main(){
    int A[500000],n,i;
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        scanf("%d",&A[i]);
    }
    mergesort(A,0,n);
    cout<<cnt<<endl;

    return 0;
}

