#include<iostream>
#include<stdio.h>
#include<vector> // 可変長配列
using namespace std;
static const int MAX = 1000000;


void printLine(int A[], int N) {
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
}

int insertionSort(int A[], int N, int g) {
    int cnt = 0;
    for (int i = g; i < N;i++) {
        int seq = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > seq) {
            A[j + g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j + g] = seq;
    }
    return cnt;
}

int shellSort(int A[], int N) {
    // 可変長配列でshell sortの幅を生成
    // この段階では昇順[1, 3, 9...]
    vector<int> vec; 
    vec.push_back(1); // append
    for (int i = 1;;) {
        i = i * 3;
        if (i > N) {
            break;
        }
        vec.push_back(i); // append
    }
    
    // 幅リストのサイズ
    int s = vec.size();
    printf("%d\n", s);
    
    int cnt = 0;
    // 降順に評価
    
    for (int i = s - 1;i >= 0;i--) {
        if (i < s - 1) {
            printf(" ");
        }
        printf("%d", vec[i]);
        cnt += insertionSort(A, N, vec[i]);
    }
    printf("\n");
    return cnt;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int A[MAX];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    //insertionSort(A, N, 1);
    int cnt = shellSort(A, N);
    printf("%d\n", cnt);
    for (int i = 0; i < N; i++) {
        printf("%d\n", A[i]);
    }
     
    return 0;
}

