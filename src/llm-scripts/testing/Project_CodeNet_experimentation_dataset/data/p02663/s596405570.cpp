#include <stdio.h>


int main(){

int menit;
int angkaangka[5];
for(int i=0;i<5; i++){
    scanf("%d", &angkaangka[i]);
}
//for(int i=0;i<5; i++){
//   printf("%d ", angkaangka[i]);
//}
int jam=angkaangka[2]-angkaangka[0];
//printf("total jam: %d\n", jam);
if(angkaangka[3]>angkaangka[1]){
    menit=angkaangka[3]-angkaangka[1];
}
else if(angkaangka[1]>angkaangka[3]){
    menit=60-(angkaangka[1]-angkaangka[3]);
    jam--;
}
else{
    menit=0;
}
//printf("total menit=%d\n", menit);
//printf("total k= %d\n", angkaangka[4]);
printf("%d\n", jam*60+menit-angkaangka[4]);





    return 0;
}