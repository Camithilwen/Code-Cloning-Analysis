#include<stdio.h>

int main()
{
    int N, count=0, min, i=0;

    scanf("%d", &N);

    int P[N+5];

    while(i != N)
    {
        scanf("%d", &P[i]);
        i++;
    }

    if(P[0] <= N)
        {
            count++;
            //printf("1st count = %d\n", count);
            min = P[0];
        }

    for(i=1; i<N; i++)
    {
        if(P[i] < min)
        {
            min = P[i];
            count++;
            //printf("count = %d\nmin = %d=%d\n", count, i, min);
        }
    }

    printf("%d\n", count);

    return 0;
}
