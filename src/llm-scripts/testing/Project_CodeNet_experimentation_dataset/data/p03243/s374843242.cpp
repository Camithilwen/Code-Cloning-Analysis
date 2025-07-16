#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;
int main(void){
    int N; cin >> N;
    int i = 0;
    int answer = 0;
    if (N / 100 > (N - N / 100 * 100) / 10) answer = N / 100;
    else if (N / 100 < (N - N / 100 * 100) / 10) answer = N / 100 + 1;
    else if ((N - N / 100 * 100) / 10 >= N % 10) answer = N / 100;
    else answer = N / 100 + 1;
    cout << answer << answer << answer << endl;
}