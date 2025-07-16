#include <iostream>
#include <utility>
#include <cstdio>
using namespace std;

void insertionSort(int A[], const int n, const int g, int *cnt)
{
    for( int i = g; i < n; ++i ){
        int tmp = A[i];
        int j = i - g;
        while( -1 < j && tmp < A[j] ){
            //cout << A[j+g] << "<-->" << A[j] << endl;
            A[j+g] = A[j];
            j = j - g;
            ++*cnt;
        }
        A[j+g] = tmp;
    }
}

void shellSort(int A[], const int n)
{
    int cnt = 0;
    int m;
    int G[100];
    for( int i = 0; i < 100; ++i ){
        if( i == 0 ) G[i] = n / 2 + 1;
        else G[i] = G[i-1] / 2 - 1;
        if( G[i] < 0 ){
            G[i-1] = 1;
            G[i] = 0;
            m = i;
            break;
        }
    }

    for( int i = 0; i < m; ++i )
        insertionSort(A, n, G[i], &cnt);

    //出力
    printf("%d\n", m);
    for( int i = 0; i < m; ++i ){
        if( i ) printf(" ");
        printf("%d", G[i]);
    }
    printf("\n%d\n", cnt);
    for( int i = 0; i < n; ++i )
        printf("%d\n", A[i]);
}

int main()
{
    //入力
    int n;
    scanf("%d", &n);
    int A[n];
    for( int i = 0; i < n; ++i )
        scanf("%d", &A[i]);

    //シェルソート
    shellSort(A, n);

    return 0;
}
