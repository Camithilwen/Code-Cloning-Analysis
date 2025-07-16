#include<iostream>
using namespace std;
int main(void)
{
    int n,m,mo[1001],bo[1001],ans[1001],A=0,i2;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        ans[i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>mo[i];
    }
    for(int i=0;i<m;i++){
        cin>>bo[i];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mo[j]<=bo[i]){
                i2=j;
                break;
            }

        }
        ans[i2]+=1;
    }
    for(int i=0;i<n;i++){
        if(A<ans[i]){
            A=ans[i];
            i2=i;
        }
    }
    cout<<i2+1<<"\n";
}