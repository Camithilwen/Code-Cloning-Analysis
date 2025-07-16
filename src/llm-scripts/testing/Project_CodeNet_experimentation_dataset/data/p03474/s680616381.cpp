#include<stdio.h>

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);
    int size = A + B + 1;
    
    char str[100];
    scanf("%s", str);
    
    int i, count = 0;
    
    if (str[A] == '-')
    {
        for (i = 0; i < size; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                count++;
            }
        }
        
        if (count == size - 1)
        {
            printf("Yes\n");
        }
        
        else
        {
            printf("No\n");
        }
    }
    
    else
    {
        printf("No\n");
    }
    
    return 0;
}