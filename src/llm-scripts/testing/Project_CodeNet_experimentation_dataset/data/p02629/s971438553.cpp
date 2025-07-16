#include <stdio.h>

int main()
{
    long long int n;
    
    scanf ("%lld",&n);
    char out[100]={0};
    int i=0;
    
    n--;
    while(n>=0){
        out[i]= n%26 +'a';
        n/=26;
        i++;
        n--;
    }
    for(int j=i-1; j>=0; j--){
        printf("%c",out[j]);
    }
    return 0;
}