#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void insertionSort(int array[], int N, int g, int *cnt){
    int i,j,v;
    for(i = g; i < N; i++){
        v = array[i];
        j = i - g;
        while( j >= 0 && array[j] > v){
            array[j+g] = array[j];
            j = j - g;
            (*cnt)++;
        }
        array[j+g] = v;
    }
    return;
}



int main(int argc, const char * argv[]){
    
    //Input
    int i, N, value, ans;
    int cnt = 0;
    scanf("%d", &N);
    
    int *array = NULL;
    array = (int*)malloc(sizeof(int) * N);
    
    REP(i, N){
        scanf("%d", &value);
        array[i] = value;
    }
    
    int m;
    int G[100];
    for( i = 0; i < 100; ++i ){
        if( i == 0 ) G[i] = N / 2 + 1;
        else G[i] = G[i-1] / 2 - 1;
        if( G[i] < 0 ){
            G[i-1] = 1;
            G[i] = 0;
            m = i;
            break;
        }
    }
    
    
    ans = 0;
    for(int i = 0; i < m; i++){
        insertionSort(array, N, G[i], &cnt);
    }
    
    //print m
    printf("%d\n", m);
    
    //print G[]
    for(i = 0; i < m; i++){
        printf("%d", G[i]);
        if(i != m-1){
            printf(" ");
        }
    }
    printf("\n");
    
    //print cnt
    printf("%d\n", cnt);
    
    
    
    REP(i, N){
        printf("%d\n", array[i]);
    }
    return 0;
}