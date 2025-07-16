#include <stdio.h>

int main(){
    int num, angka1, angka2, angka3;
    scanf("%d", &num);

    angka1 = num/100;
    angka2 = (num - angka1 * 100)/10;
    angka3 = num % (angka1 * 100 + angka2 * 10);
if(angka1 == 7 || angka2 == 7 || angka3 == 7){
    puts("Yes");
} else{
    puts("No");
}
    return 0;
}