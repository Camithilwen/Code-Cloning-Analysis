#include<stdio.h>
int main()
{
    int A, B, C, D, X, Y;
    scanf("%d%d%d%d",&A, &B, &C, &D);
    if(A>B){X=B;}
       else{
        X = A;
    }
    if (C>D){Y=D;}
        else {
        Y = C;
    }
    printf("%d\n", (X+Y) );

    return 0;

}
