#include <stdio.h>

int main (){
	int baris,kolom,warna,x;
	
	scanf ("%d",&baris);
	scanf ("%d",&kolom);
	scanf ("%d",&warna);
	
	if (baris > kolom){
        x = (warna - 1)/baris +1;
    }
    else {
        x = (warna - 1)/kolom +1;
    }
    
	printf ("%d",x);
	
	return 0;
}