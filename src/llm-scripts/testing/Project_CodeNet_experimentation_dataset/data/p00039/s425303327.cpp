#include <stdio.h>

int main(void){
    char fig[101];
    int num;
    
    while (scanf("%s", fig) != EOF){
        num = 0;
        for (char *pt=fig; *pt!='\0'; pt++){
            switch (*pt){
            case 'I':
                switch(*(pt+1)){
                case 'V':
                    num += 4;
                    pt++;
                    break;
                case 'X':
                    num += 9;
                    pt++;
                    break;
                default:
                    num += 1;
                    break;
                }
                break;
            case 'V':
                num += 5;
                break; 
            case 'X':
                switch(*(pt+1)){
                case 'L':
                    num += 40;
                    pt++;
                    break;
                case 'C':
                    num += 90;
                    pt++;
                    break;
                default:
                    num += 10;
                    break;
                }
                break;
            case 'L':
                num += 50;
                break;
            case 'C':
                switch(*(pt+1)){
                case 'D':
                    num += 400;
                    pt++;
                    break;
                case 'M':
                    num += 900;
                    pt++;
                    break;
                default:
                    num += 100;
                    break;
                }
                break;
            case 'D':
                num += 500;
                break;
            case 'M':
                num += 1000;
                break;
            }
        }
        printf("%d\n", num);
    }
        
    return 0;
}