#include<stdio.h>
int main (){
	int ha;
	int wa;
	int na;
	int hasil;
	
	scanf("%d", &ha);
	scanf("%d", &wa);
	scanf("%d", &na);
	
	if(ha>=wa){
        if(na%ha == 0) {
            hasil = na/ha;
        } else {
            hasil = na/ha+1;
        }
    } else {
        if(na%wa == 0) {
            hasil = na/wa;
        } else {
            hasil = na/wa+1;
        }
    }
    printf("%d", hasil);
	return 0;
}
