#include <stdio.h>

int main(){
    int year;
    int month;
    int day;
    scanf("%d/%d/%d", &year, &month, &day);
    printf("2018/%02d/%02d\n", month, day);

    return 0;

}