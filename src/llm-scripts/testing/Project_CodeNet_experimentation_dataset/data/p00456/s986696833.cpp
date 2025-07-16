#include<iostream>
using namespace std;
int main(){
int w[10],k[10],tmp,i,j;
for(i=0;i<10;i++){
cin>>w[i];
}
for(i=0;i<10;i++){
cin>>k[i];
}
for(i=0;i<9;i++){
for(j=9;j>i;j--){
if(w[j]>=w[j-1]){
tmp=w[j];
w[j]=w[j-1];
w[j-1]=tmp;
}
if(k[j]>=k[j-1]){
tmp=k[j];
k[j]=k[j-1];
k[j-1]=tmp;
}
}
}
cout<<w[0]+w[1]+w[2]<<" "<<k[0]+k[1]+k[2]<<endl;
return 0;
}