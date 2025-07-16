#include<bits/stdc++.h>
using namespace std;
int ap[1005],bp[1005],cp[1005],abc[1005],r[1005];
int n,n1,n2,n3;

int main(){

    while(1){

    cin >> n1 >> n2 >> n3;
    if(n1==0&&n2==0&&n3==0)break;
    cin >> n;

   for(int i=0;i<=n1+n2+n3;i++)abc[i]=2;

    for(int i=0;i<n;i++){

        cin >> ap[i] >> bp[i] >> cp[i] >> r[i];

        if(r[i]==1){
        abc[ap[i]]=1,abc[bp[i]]=1,abc[cp[i]]=1;
        }
    }

    for(int i=0;i<n;i++){
     if(abc[ap[i]]==1&&abc[bp[i]]==1&&r[i]==0)abc[cp[i]]=0;
     else if(abc[cp[i]]==1&&abc[bp[i]]==1&&r[i]==0)abc[ap[i]]=0;
     else if(abc[cp[i]]==1&&abc[ap[i]]==1&&r[i]==0)abc[bp[i]]=0;
    }

    for(int i=1;i<n1+n2+n3+1;i++)cout << abc[i] << endl;

    }


return 0;
}