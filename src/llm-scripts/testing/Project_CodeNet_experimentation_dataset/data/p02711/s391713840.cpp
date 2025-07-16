#include <stdio.h>
 
int main(){
	
int angka,ratusan,puluhan,satuan;
	
scanf("%d", &angka);
	
ratusan = angka % 100;
puluhan = ratusan % 10;
satuan = puluhan;
puluhan = ratusan / 10;
ratusan = angka / 100;
		
if (ratusan == 7){
	printf("Yes\n");
}
	
else if(puluhan == 7){
	printf("Yes\n");
}
	
else if(satuan == 7){
	printf("Yes\n");
}
else{
	printf("No\n");
}

return 0;
}
