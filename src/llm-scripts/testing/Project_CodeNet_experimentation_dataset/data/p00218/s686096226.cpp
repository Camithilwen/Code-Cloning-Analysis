#include<stdio.h>

//this file is not a C file but a C++ file                                      
void seisekiduke(void);//宣言                                                   

int main(void){
    int stnum;//the number of the student                                       
    while(1) {
        scanf(" %d", &stnum);
        if(stnum == 0) {
            break;
        }
        for(int i = stnum - 1;i >= 0;i -= 1) {
            seisekiduke();//一名の生徒の成績を付ける                            
        }
    }
    return 0;
}

void seisekiduke(void) {
    int pm, pe, pj = 0;//score                                                  
    char grade;
     scanf(" %d %d %d", &pm, &pe, &pj);
        if((pm == 100 || pe == 100 || pj == 100) ||
           (pm + pe) / 2 >= 90                   ||
           (pm + pe + pj) / 3 >= 80) {
           grade = 'A';
        }else if((pm + pe + pj) / 3 >= 70 ||
                (((pm + pe + pj) / 3 >= 50) && (pm >= 80 || pe >= 80))){
            grade = 'B';
        }else{
            grade = 'C';
        }
        printf("%c\n", grade);

}