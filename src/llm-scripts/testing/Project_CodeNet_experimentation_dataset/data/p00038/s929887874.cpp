#include <stdio.h>
int main(){
int x[5],i,j;
while(scanf("%d,%d,%d,%d,%d",&x[0],&x[1],&x[2],&x[3],&x[4])!=EOF){
for(j=0;j<5;j++){
for(i=0;i<4;i++){
if(x[i]>x[i+1]){
int g=x[i+1];
x[i+1]=x[i];
x[i]=g;
}}}
if(x[0]==x[1] && x[1]==x[2] && x[2]==x[3]){
printf("four card\n");
continue;
}
if(x[1]==x[2] &&x[2]==x[3]&&x[3]==x[4]){
printf("four card\n");
continue;
}
if(x[0]==x[1]&&x[1]==x[2]&&x[3]==x[4]){
printf("full house\n");
continue;
}
if(x[0]==x[1]&&x[2]==x[3]&&x[3]==x[4]){
printf("full house\n");
continue;
}
if(x[0]<=10 && x[0]+1==x[1]&&x[1]+1==x[2]&&x[2]+1==x[3]&&x[3]+1==x[4]){
printf("straight\n");
continue;
}
if(x[0]==1&&x[1]==10&&x[2]==11&&x[3]==12&&x[4]==13){
printf("straight\n");
continue;
}
if(x[0]==x[1]&&x[1]==x[2]){
printf("three card\n");
continue;
}
if(x[1]==x[2]&&x[3]==x[2]){
printf("three card\n");
continue;
}
if(x[2]==x[3]&&x[3]==x[4]){
printf("three card\n");
continue;
}
if(x[0]==x[1] && x[2]==x[3]){
printf("two pair\n");
continue;
}
if(x[0]==x[1] && x[2]==x[3]){
printf("two pair\n");
continue;
}
if(x[0]==x[1]&&x[3]==x[4]){
printf("two pair\n");
continue;
}
if(x[1]==x[2]&&x[3]==x[4]){
printf("two pair\n");
continue;
}
if(x[0]==x[1]){
printf("one pair\n");
continue;
}
if(x[2]==x[1]){
printf("one pair\n");
continue;
}
if(x[2]==x[3]){
printf("one pair\n");
continue;
}
if(x[3]==x[4]){
printf("one pair\n");
continue;
}
printf("null\n");
}
return 0;
}