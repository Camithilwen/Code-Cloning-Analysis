#include <stdio.h>
int main(void){
int A,B;
scanf ("%d %d",&A,&B);
if (B+2<=A) printf ("%d",A+(A-1));
if (A+2<=B) printf ("%d",B+(B-1));
else {
    if (A==B+1||B==A+1||A==B) printf ("%d",A+B);
}
}
