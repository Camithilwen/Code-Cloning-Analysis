#include<stdio.h>
//operation a == doubled
//operation b == increase by b
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int result = 1;
    for(int i = 0; i < a; i++){
        if(result < b)//it works if result + b is smaller than doubled
        {
            result = result * 2;
        }
        else//it works if result * 2 is smaller than doubled
        {
            result = result + b;
        }
    }
    printf("%d\n", result);
    return 0;
}