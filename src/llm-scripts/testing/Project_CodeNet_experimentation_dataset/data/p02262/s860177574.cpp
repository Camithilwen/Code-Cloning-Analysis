#include<stdio.h>
#include<iostream>
using namespace std;

void insert_sort(long int *num,long int n,long int g,long int *cnt);
int main(){
        long int cnt[1];
        long int num[1000000];
        long int n;
        long int i;
        long int m[1000000];
        long int count=0;
        long int k;
        int yn=0;
        cnt[0]=0;

        cin>>n;
        for(i=0;i<n;i++){
                cin>>num[i];
        }
        m[0]=n-1;
        while(yn==0){
                yn=1;
                insert_sort(num,n,m[count],cnt);
                count++;
                m[count]=m[count-1]/2;

                for(i=0;i<n-1;i++){
                        if(num[i]>num[i+1]){
                                yn=0;
                                break;
                        }   
                }
     
        }
        cout<<count<<endl;
        for(i=0;i<count;i++){
                cout<<m[i];
                if(i<count-1){
                        cout<<" ";
                }else{
                        cout<<endl;
                }
        }
        cout<<cnt[0]<<endl;
        for(i=0;i<n;i++){
                cout<<num[i]<<endl;
        }
        return 0;
}

void insert_sort(long int *num,long int n,long int g,long int *cnt){
        long int i;
        long int j;
        long int k;
        long int tmp;
        long a;
        a=cnt[0];
        for(i=g;i<n;i++){
                tmp=num[i];
                j=i-g;
                while((j>=0)&&(tmp<num[j])){
                        num[j+g]=num[j];
                        j-=g;
                        cnt[0]++;
                }
                num[j+g]=tmp;
        }
}