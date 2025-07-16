#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int number;
    int sum = 0;
    
    while(1){
        cin >> number;
        if (number == 0){
            break;
        }
        
       
        int array[number][number];
        int lastColumn[number];
        int lastRow[number];
        int total=0;
        
        for(int i=0; i<number; i++){
            sum = 0;
            for(int j=0; j<number; j++){
                cin >> array[i][j];
                sum += array[i][j];
            }
            lastColumn[i] = sum;
        }
        
        for(int j=0; j<number; j++){
            sum = 0;
            for(int i=0; i<number; i++){
                sum += array[i][j];
            }
            lastRow[j] = sum;
            total +=sum;
        }
        
        for(int i=0; i<number; i++){
            for(int j=0; j<number; j++){
                printf("%5d", array[i][j]);
            }
            printf("%5d\n", lastColumn[i]);
        }
        
        for(int i=0; i<number; i++){
            printf("%5d", lastRow[i]);
         }
        printf("%5d\n", total);

    }
    
    return 0;
}