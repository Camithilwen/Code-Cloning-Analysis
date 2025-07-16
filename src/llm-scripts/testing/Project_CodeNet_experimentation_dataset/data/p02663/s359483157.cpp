#include <stdio.h>
int main()
{
    int hour_1;
    int hour_2;
    int min_1;
    int min_2;
    int k;
    scanf("%d %d %d %d %d", &hour_1, &min_1, &hour_2, &min_2, &k);
    int total_hour = hour_2 - hour_1;
    int total_minute = min_2 - min_1;
    int duration = (total_hour * 60) + total_minute - k;
    printf("%d\n", duration);
}